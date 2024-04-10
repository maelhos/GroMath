/**
 * GroMath
 *
 *
 * Examples:
 *
 * Atom: 42, foo, bar, "Hello World"
 *
 * List: (), (+ 5 x), (print "hello")
 */

// -----------------------------------------------
// Lexical grammar (tokens):

%lex

%%

\/\/.*             %empty
\/\*[\s\S]*?\*\/   %empty

\s+                %empty

\"[^\"]*\"         ConstString

\d+                ConstInt

[a-zA-Z_$][a-zA-Z_$0-9]* Identifier


/lex

// -----------------------------------------------
// Syntactic grammar (BNF):

%{

#include "ast.hpp"

using Value = std::unique_ptr<MainAST>;

%}

%%


Main 
    : %empty { $$ = std::make_unique<MainAST>(); }
    | Main ObjDecl { $1->AddObjDecl($2); $$ = std::move($1);}
    | Main FnDecl  { $1->AddFnDeclAST($2); $$ = std::move($1);}
    ;

ObjDecl 
    : "obj" Identifier "{" TypedIdentifierList "}"
    ;

BasicType
    : Identifier
    ;

Type 
    : BasicType // [check:existing_type]
    | FunctionType // represent function type (for now expression will just be constexpr...)
    ;

FunctionType 
    : BasicType
    | BasicType "->" FunctionType 
    ;
    
NonEmptyTypedIdentifierList 
    : Type Identifier
    | Type Identifier "," NonEmptyTypedIdentifierList
    ;

TypedIdentifierList 
    : %empty
    | NonEmptyTypedIdentifierList
    ;

NonEmptyIdentifierList 
    : Identifier
    | Identifier "," NonEmptyIdentifierList
    ;

IdentifierList 
    : %empty
    | NonEmptyIdentifierList
    ;

FnDecl 
    : "fn" Identifier "(" TypedIdentifierList  ")" "->" Type Block
    ;

ControlFlow 
    : "if" "(" Expr ")" Block
    | "if" "(" Expr ")" Block "else" Block
    | "while" "(" Expr ")" Block
    | "for" "(" Expr ";" Expr ";" Expr ")" Block
    ;

StatementList 
    : %empty
    | Statement ";" StatementList
    | ControlFlow StatementList
    ;

Block
    : Statement
    | "{" StatementList "}"
    ;

FunctionCall 
    : Identifier "(" IdentifierList ")"
    ;

AssigementOperator
    : "="
    | "+="
    | "-="
    | "*="
    | "/="
    | "%="
    | "^="
    | "<<="
    | ">>="
    | "^^="
    ;

PostFixOperator 
    : "++"
    | "--"
    ;

PrefixOperator
    : "!"
    | "-"
    ;

BinaryOperator
    : "+"
    | "-"
    | "*"
    | "/"
    | "%"
    | "<<"
    | ">>"
    | "^"
    | "^^"
    | "&"
    | "|"
    | "&&"
    | "||"
    ;

ConstExpr 
    : ConstString
    | ConstInt
    ;

Expression 
    : Expression BinaryOperator Expression
    | PrefixOperator Expression
    | FunctionCall
    | "(" Expression ")"
    | ConstExpr
    ;

Statement
    : Type Identifier
    | Type Identifier "=" Expression
    | Identifier AssigementOperator Expression
    | Identifier PostFixOperator
    | FunctionCall
    | "ret" 
    | "ret" Expression
    | "break"
    | "continue"
    ;
