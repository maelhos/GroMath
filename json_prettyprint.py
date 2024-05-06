from graphviz import *

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
        return 
    elif (json['token'] in ['integer', 'double', 'bool', 'string', 'identifier']):
        g.node(f'{i}', json['token'])
        g.node(f'{i + 1}', json['value'])
        g.edge(f'{i}', f'{i + 1}')
        i += 2
        return
    elif (json['token'] == 'method'):
        g.node(f'{i}', json['token'])
        g.node(f'{i + 1}', json['id'])
        j = i # we keep our old i to do the linkage in the graph !
        i += 2
        for elem in json['arguments']:
            handle_expression(g, elem, dic, i)
        k = j + 1 # a cursor to get from old value of i to new value of i
        while (k != i):
            g.edge(f'{j}', f'{k}')
            k += 1
        return
    elif (json['token'] == 'operator'):
        g.node(f'{i}', json['token'])
        j = i # keeping track of our main node token 
        i += 1

        handle_expression(g, json['lhs'], dic, i)
        g.edge(f'{j}', f'{j + 1}') # linking lhs with token 

        g.node(f'{i}', dic[json['op']]) # placing our operator in the middle
        g.edge(f'{j}', f'{i}') # linking our token to the operator
        i += 1

        k = i # keeping track of the beginning of rhs
        handle_expression(g, json['rhs'], dic, i)
        g.edge(f'{j}', f'{k}') # linking rhs with token 
        return 
    elif (json['token'] == 'assignment'):
        g.node(f'{i}', json['token'])
        j = i # keeping track of our main node token
        i += 1

        handle_expression(g, json['lhs'], dic, i)
        g.edge(f'{j}', f'{i}') # linking our token to the lhs

        k = i
        handle_expression(g, json['rhs'], dic, i)
        g.edge(f'{j}', f'{k}')
        return 
    else: # case of a block
        g.node(f'{i}', json['token'])
        j = i # keeping track of our main token
        i += 1
        for element in json['statements']:
            k = i # main token of the current statement
            handle_statement(g, element, dic, i)
            g.edge(f'{j}', f'{k}') # linking our main token to the statement 
        return

def handle_statement(g, json, dic, i = 0):
    if (json == {}):
        return 
    elif (json['token'] == 'return'):
        g.node(f'{i}', json['token'])
        g.node(f'{i + 1}', json['returnExpr'])
        g.edge(f'{i}', f'{i + 1}')
        i += 2
        return
    elif (json['token'] == 'expression'):
        handle_expression(g, json['expr'], dic, i)
        return 
    elif (json['token'] in ['continue', 'break']):
        g.node(f'{i}', json['token'])
        i += 1
        return
    elif (json['token'] == 'if'):
        g.node(f'{i}', json['token'])
        j = i 
        i += 1

        return
    elif (json['token'] == 'while'):
        g.node(f'{i}', json['token'])
        j = i
        i += 1

        return



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


def get_json():
    """
    Function that handles getting the json token to then convert this all into a big tree.
    """
    j = {}
    with open('out_ast.json', 'r') as f:
        j = f.read()
    return j

def main():
    print("[*] Getting Dictionnary")
    d = parse_tokens()
    print("[+] Dictionnary found : ")
    
    print("[*] Getting Json")
    j = get_json()
    print("[+] Json found!")

    print("[*] Now generating tree")
    show_tree(j, d)

    return 0


if __name__ == '__main__':
    main()



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
- variableDeclaration (with id, type and expression)
- functionDeclaration (with id, type, arguments and block)
- iterator (with start, stop and incr)
- for (with declaration, iter and block)
"""
