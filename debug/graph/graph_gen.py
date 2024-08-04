from graphviz import *
import json

"""
for this part, we'll get the json extracted using virtual methods implemented in json.cpp to retrieve some kind of json conversion of our ASTs
then it's time to use treelib to pretty-print it, and that is what this python script is all about !
"""

def parse_tokens():
    """
    Recuperating tokens from the file src/parser.cpp to get the symbol corresponding to each value in symbol_kind enum.
    to do so, I first find the beginning of enum type,
    then I just recuperate the tuple for each line until the end of enum.
    
    The return type is a dictionnary because value are not contiguous and some are negatives.
    """
    l = []
    i = 0
    with open('include/parser.hpp', 'r') as f:
        r = f.read().split('\n')
        for i in range(len(r)):
            if 'enum yytokentype' in r[i]:
                break
        i += 2
        while not ('};' in r[i]):
            current_line = r[i][4:] # removing the double tabulation
            symbols = current_line.split(' = ')
            if (',' in symbols[1]): # two cases : last token or not
                corresponding_integer = int(symbols[1].split(',')[0])
            else:
                corresponding_integer = int(symbols[1].split(' ')[0])
            l.append((corresponding_integer, symbols[0]))
            i += 1
    return dict(l)

def handle_expression(g, json, dic, i = 0):
    if (json == {}):
        return i
    elif (json['token'] in ['integer', 'double', 'bool', 'string', 'identifier']):
        g.node(f'{i}', json['token'])
        g.node(f'{i + 1}', str(json['value']))
        g.edge(f'{i}', f'{i + 1}')
        i += 2
        return i
    elif (json['token'] == 'method'):
        g.node(f'{i}', json['token'])
        j = i # we keep our old i to do the linkage in the graph !
        i += 1

        i = handle_expression(g, json['id'], dic, i)
        g.edge(f'{j}', f'{j + 1}')

        g.node(f'{i}', "arguments")
        g.edge(f'{j}', f'{i}')
        j = i
        i += 1

        k = i # a cursor to get from old value of i to new value of i
        for elem in json['arguments']:
            i = handle_expression(g, elem, dic, i)
            g.edge(f'{j}', f'{k}')
            k = i
        return i
    elif (json['token'] == 'operator'):
        g.node(f'{i}', json['token'])
        g.node(f'{i + 1}', dic[json['op']])
        g.edge(f'{i}', f'{i + 1}')
        j = i
        i += 2

        k = i
        i = handle_expression(g, json['lhs'], dic, i)
        g.edge(f'{j}', f'{k}')

        k = i 
        i = handle_expression(g, json['rhs'], dic, i)
        g.edge(f'{j}', f'{k}')
        return i
    elif (json['token'] == 'assignment'):
        g.node(f'{i}', json['token'])
        j = i
        i += 1

        k = i
        i = handle_expression(g, json['lhs'], dic, i)
        g.edge(f'{j}', f'{k}')

        k = i 
        i = handle_expression(g, json['rhs'], dic, i)
        g.edge(f'{j}', f'{k}')
        return i
    elif (json['token'] == 'block'):
        g.node(f'{i}', json['token'])
        j = i
        i += 1

        k = i
        for elem in json['statements']:
            i = handle_statement(g, elem, dic, i)
            g.edge(f'{j}', f'{k}')
            k = i
        return i
    else:
        print("error : unknown expression...")
        assert(False)


def handle_statement(g, json, dic, i = 0):
    if (json['token'] == 'if'):
        g.node(f'{i}', json['token'])
        j = i
        i += 1

        g.node(f'{i}', "condition")
        g.edge(f'{j}', f'{i}')
        k = i
        i += 1

        l = i
        i = handle_expression(g, json['condition'], dic, i)
        g.edge(f'{k}', f'{l}')

        g.node(f'{i}', "ifblock")
        g.edge(f'{j}', f'{i}')
        k = i
        i += 1

        l = i
        i = handle_expression(g, json['ifblock'], dic, i)
        g.edge(f'{k}', f'{l}')

        if (json['elseblock'] != {}):
            g.node(f'{i}', "elseblock")
            g.edge(f'{j}', f'{i}')
            k = i
            i += 1

            l = i
            i = handle_expression(g, json['elseblock'], dic, i)
            g.edge(f'{k}', f'{l}')
        return i
    elif (json['token'] in ['break', 'continue']):
        g.node(f'{i}', json['token'])
        j = i
        i += 1
        return i
    elif (json['token'] == 'return'):
        g.node(f'{i}', json['token'])
        j = i
        i += 1

        g.node(f'{i}', "returnExpr")
        g.edge(f'{j}', f'{i}')
        k = i
        i += 1

        l = i
        i = handle_expression(g, json['returnExpr'], dic, i)
        g.edge(f'{k}', f'{l}')

        return i
    elif (json['token'] == 'while'):
        g.node(f'{i}', json['token'])
        j = i
        i += 1

        g.node(f'{i}', "condition")
        g.edge(f'{j}', f'{i}')
        k = i
        i += 1

        l = i
        i = handle_expression(g, json['condition'], dic, i)
        g.edge(f'{k}', f'{l}')

        l = i
        i = handle_expression(g, json['block'], dic, i)
        g.edge(f'{j}', f'{l}')
        return i
    elif (json['token'] == 'expression'):
        return handle_expression(g, json['block'], dic, i)
    elif (json['token'] == 'variableDeclaration'):
        g.node(f'{i}', json['token'])
        j = i
        i += 1

        i = handle_expression(g, json['id'], dic, i)
        g.edge(f'{j}', f'{j + 1}')

        g.node(f'{i}', "type")
        g.edge(f'{j}', f'{i}')
        l = i
        i += 1
        k = i
        for elem in json['typed']:
            i = handle_expression(g, elem, dic, i)
            g.edge(f'{l}', f'{k}')
            k = i

        g.node(f'{i}', "expression")
        g.edge(f'{j}', f'{i}')
        k = i
        i += 1

        l = i
        i = handle_expression(g, json['expression'], dic, i)
        g.edge(f'{k}', f'{l}')
        return i
    elif (json['token'] == 'functionDeclaration'):
        g.node(f'{i}', json['token'])
        j = i
        i += 1

        i = handle_expression(g, json['id'], dic, i)
        g.edge(f'{j}', f'{j + 1}')

        g.node(f'{i}', "type")
        g.edge(f'{j}', f'{i}')
        l = i
        i += 1
        k = i
        for elem in json['typed']:
            i = handle_expression(g, elem, dic, i)
            g.edge(f'{l}', f'{k}')
            k = i
        
        g.node(f'{i}', "arguments")
        g.edge(f'{j}', f'{i}')
        l = i
        i += 1

        k = i # a cursor to get from old value of i to new value of i
        for elem in json['arguments']:
            i = handle_expression(g, elem, dic, i)
            g.edge(f'{l}', f'{k}')
            k = i

        l = i
        i = handle_expression(g, json['block'], dic, i)
        g.edge(f'{j}', f'{l}')
        return i
    elif (json['token'] == 'iterator'):
        g.node(f'{i}', json['token'])
        j = i
        i += 1

        g.node(f'{i}', "start")
        g.edge(f'{j}', f'{i}')
        k = i
        i += 1

        l = i
        i = handle_expression(g, json['start'], dic, i)
        g.edge(f'{k}', f'{l}')

        g.node(f'{i}', "stop")
        g.edge(f'{j}', f'{i}')
        k = i
        i += 1

        l = i
        i = handle_expression(g, json['stop'], dic, i)
        g.edge(f'{k}', f'{l}')

        g.node(f'{i}', "increment")
        g.edge(f'{j}', f'{i}')
        k = i
        i += 1

        l = i
        i = handle_expression(g, json['increment'], dic, i)
        g.edge(f'{k}', f'{l}')

        g.node(f'{i}', "end")
        g.edge(f'{j}', f'{i}')
        k = i
        i += 1

        g.node(f'{i}', str(json['end']))
        g.edge(f'{k}', f'{i}')
        i += 1
        return i
    elif (json['token'] == 'for'):
        g.node(f'{i}', json['token'])
        j = i
        i += 1

        g.node(f'{i}', "declaration")
        g.edge(f'{j}', f'{i}')
        k = i
        i += 1

        l = i
        i = handle_expression(g, json['declaration'], dic, i)
        g.edge(f'{k}', f'{l}')

        g.node(f'{i}', "iter")
        g.edge(f'{j}', f'{i}')
        k = i
        i += 1

        l = i
        i = handle_expression(g, json['iter'], dic, i)
        g.edge(f'{k}', f'{l}')

        l = i
        i = handle_expression(g, json['block'], dic, i)
        g.edge(f'{j}', f'{l}')
        return i
    else:
        print("error : unknown statement...")
        assert(False)


def show_tree(json, dic):
    """
    converting this json squigligli to a beautiful tree using the library treelib.
    g.render('tests/output.gv')
    The dictionnary could be useful if we have an operator as the op is just a number in our json chan.
    """
    g = Graph(format='png')
    if (json == {}):
        g.view()
        return
    if (json['type'] == 'expression'):
        handle_expression(g, json, dic)
        g.view()
        return
    # case of a statement
    handle_statement(g, json, dic)
    g.view()
    return


def get_json(file):
    """
    Function that handles getting the json token to then convert this all into a big tree.
    """
    j = {}
    with open(file, 'r') as f:
        j = f.read()
    return json.loads(j)


def test(i):
    print("[*] Getting Dictionnary")
    d = parse_tokens()
    print("[+] Dictionnary found : ")
    
    print("[*] Getting Json")
    j = get_json(f'tests/json/test{i}.json')
    print("[+] Json found!")
    print(j)

    print("[*] Now generating tree")
    show_tree(j, d)
    return



def main():
    print("[*] Getting Dictionnary")
    d = parse_tokens()
    print("[+] Dictionnary found : ")
    
    print("[*] Getting Json")
    j = get_json('out_ast.json')
    print("[+] Json found!")
    print(j)

    print("[*] Now generating tree")
    show_tree(j, d)

    return 0


if __name__ == '__main__':
    main()
    # for i in range(1, 13):
    #     test(i)
    #     res = input("waiting for approval")
    #     if (res == 'NOP'):
    #        assert(False)



"""
kinds of json we can get :

expressions : (tokens)
- integer, string, double, bool, identifier (with value in dict)
- method (with id and arguments in dict)
- operator (with op and lhs/rhs)
- assignment (with rhs/lhs)
- block (with statements)

statements :
- if (with condition, ifblock and elseblock)
- break, continue
- return (with returnExpr)
- while (with condition and block)
- expression (with expr)
- variableDeclaration (with id, typed and expression)
- functionDeclaration (with id, typed, arguments and block)
- iterator (with start, stop and incr)
- for (with declaration, iter and block)
"""
