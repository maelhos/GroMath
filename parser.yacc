%{
    #include "node.h"
    NBlock* programBlock; /* the top level root node of our final AST */

    extern int yylex();
    void yyerror(const char *s) { printf("ERROR: %s\n", s); }
%}

/* Represents the many different ways we can access our data */
%union {
    Node* node;
    NBlock* block;
    NExpression* expr;
    NStatement* stmt;
    NIdentifier* ident;
    NVariableDeclaration* var_decl;
    NIterator* iter;
    std::vector<NVariableDeclaration*>* varvec;
    std::vector<NExpression*>* exprvec;
    std::string* string;
    int token;
}

/* Define our terminal symbols (tokens). This should
   match our tokens.l lex file. We also define the node type
   they represent.
 */
%token <string> TIDENTIFIER TINTEGER TCSTSTRING // TDOUBLE
%token <token> TTRUE TFALSE
%token <token> TCEQ TCNE TCLT TCLE TCGT TCGE TEQUAL
%token <token> TLPAREN TRPAREN TLBRACE TRBRACE TLBRACK TRBRACK TLLBRACK TRRBRACK TCOMMA TDOT TCOLON TSCOLON
%token <token> TPLUS TMINUS TMUL TDIV TMOD TPOW
%token <token> TIF TELSE TFN TWHILE TFOR TIN TRET TBREAK TCONTINUE TRANGE
%token <token> TRARROW

/* Define the type of node our nonterminal symbols represent.
   The types refer to the %union declaration above. Ex: when
   we call an ident (defined by union type ident) we are really
   calling an (NIdentifier*). It makes the compiler happy.
 */

%type <ident> ident
%type <expr> cst_int expr cst_string binop
%type <varvec> func_decl_args 
%type <exprvec> call_args type
%type <block> program stmts block
%type <stmt> stmt func_decl if_stmt for_stmt while_stmt ret_stmt break_stmt continue_stmt
%type <iter> iterator
%type <var_decl> var_decl

%start program

/* Operator precedence for mathematical operators */
%left TCEQ TCNE TCLT TCLE TCGT TCGE 
%left TMOD
%left TPLUS TMINUS
%left TMUL TDIV
%right TPOW 

%%

program : stmts { programBlock = $1; }
        ;
        
stmts : stmt { $$ = new NBlock(); $$->statements.push_back($1); }
      | stmts stmt { $1->statements.push_back($2); }
      ;

stmt : var_decl TSCOLON { $$ = (NStatement*)$1; }
     | func_decl
     | expr TSCOLON { $$ = new NExpressionStatement(*$1); }
     | if_stmt
     | for_stmt
     | while_stmt
     | ret_stmt TSCOLON
     | break_stmt TSCOLON
     | continue_stmt TSCOLON
     ;

if_stmt : TIF expr TCOLON block { $$ = new NIfStatement($2, $4); }
        | TIF expr TCOLON stmt 
            { auto tbl = new NBlock();
                   tbl->statements.push_back($4);
                   $$ = new NIfStatement($2, tbl); }
        | TIF expr TCOLON block TELSE TCOLON block { $$ = new NIfStatement($2, $4, $7); }
        | TIF expr TCOLON stmt TELSE TCOLON block
            { auto tbl = new NBlock();
                   tbl->statements.push_back($4);
                   $$ = new NIfStatement($2, tbl, $7); }
        | TIF expr TCOLON block TELSE TCOLON stmt
            { auto tbl = new NBlock();
                   tbl->statements.push_back($7);
                   $$ = new NIfStatement($2, $4, tbl); }
        | TIF expr TCOLON stmt TELSE TCOLON stmt 
            { auto tbl1 = new NBlock();
                   tbl1->statements.push_back($4);
                   auto tbl2 = new NBlock();
                   tbl2->statements.push_back($7);
                   $$ = new NIfStatement($2, tbl1, tbl2); }
        ;

iterator : TRANGE TLPAREN expr TRPAREN { $$ = new NRangeIterator($3);}
         | TRANGE TLPAREN expr TCOMMA expr TRPAREN { $$ = new NRangeIterator($3, $5);}
         | TRANGE TLPAREN expr TCOMMA expr TCOMMA expr TRPAREN { $$ = new NRangeIterator($3, $5, $7);}
         | TLLBRACK expr TCOMMA expr TRRBRACK { $$ = new NRangeIterator($2, $4, nullptr, true);}
         ;

for_stmt : TFOR var_decl TIN iterator TCOLON block { $$ = new NForStatement($2, $4, $6); }
         | TFOR var_decl TIN iterator TCOLON stmt 
                 { auto tbl = new NBlock();
                   tbl->statements.push_back($6);
                   $$ = new NForStatement($2, $4, tbl); }
         ;

while_stmt : TWHILE expr TCOLON block { $$ = new NWhileStatement($2, $4); }
           | TWHILE expr TCOLON stmt 
                { auto tbl = new NBlock();
                  tbl->statements.push_back($4);
                  $$ = new NWhileStatement($2, tbl); }
           ;

break_stmt : TBREAK {$$ = new NBreakStatement();}
           ;

continue_stmt : TCONTINUE {$$ = new NContinueStatement();}
           ;

ret_stmt : TRET {$$ = new NReturnStatement();}
         | TRET expr {$$ = new NReturnStatement($2);}
         ;

block : TLBRACE stmts TRBRACE { $$ = $2; }
      | TLBRACE TRBRACE { $$ = new NBlock(); }
      ;

type : ident { $$ = new ExpressionList(); $$->push_back($1); }
     | type TRARROW ident { $$->push_back($3); }
     ;

var_decl : ident TCOLON type { $$ = new NVariableDeclaration(*$3, *$1); }
         | ident TCOLON type TEQUAL expr { $$ = new NVariableDeclaration(*$3, *$1, $5); }
         ;
        
func_decl : TFN ident TLPAREN func_decl_args TRPAREN TCOLON type block 
            { $$ = new NFunctionDeclaration($7, *$2, *$4, *$8); delete $4; }
          ;

func_decl_args : /*blank*/  { $$ = new VariableList(); }
          | var_decl { $$ = new VariableList(); $$->push_back($1); }
          | func_decl_args TCOMMA var_decl { $1->push_back($3); }
          ;

ident : TIDENTIFIER { $$ = new NIdentifier(*$1); delete $1; }
      ;

cst_string : TCSTSTRING { $$ = new NSringConstant(*$1); delete $1; }
           ;

cst_int : TINTEGER { $$ = new NIntConstant(*$1); delete $1; }
  //    | TDOUBLE { $$ = new NDouble(atof($1->c_str())); delete $1; }
        ;
    
expr : ident TEQUAL expr { $$ = new NAssignment(*$1, *$3); }
     | ident TLPAREN call_args TRPAREN { $$ = new NMethodCall(*$1, *$3); delete $3; }
     | ident { $$ = $1; }
     | cst_int
     | cst_string
     | binop
     | TLPAREN expr TRPAREN { $$ = $2; }
     | TTRUE { $$ = new NBool(true); }
     | TFALSE { $$ = new NBool(false); }
     ;
    
call_args : { $$ = new ExpressionList(); }
          | expr { $$ = new ExpressionList(); $$->push_back($1); }
          | call_args TCOMMA expr  { $1->push_back($3); }
          ;

binop : expr TCEQ   expr { $$ = new NBinaryOperator(*$1, $2, *$3); }
      | expr TCNE   expr { $$ = new NBinaryOperator(*$1, $2, *$3); }
      | expr TCLT   expr { $$ = new NBinaryOperator(*$1, $2, *$3); }
      | expr TCLE   expr { $$ = new NBinaryOperator(*$1, $2, *$3); }
      | expr TCGT   expr { $$ = new NBinaryOperator(*$1, $2, *$3); }
      | expr TCGE   expr { $$ = new NBinaryOperator(*$1, $2, *$3); }
      | expr TPLUS  expr { $$ = new NBinaryOperator(*$1, $2, *$3); }
      | expr TMINUS expr { $$ = new NBinaryOperator(*$1, $2, *$3); } 
      | expr TMUL   expr { $$ = new NBinaryOperator(*$1, $2, *$3); }
      | expr TDIV   expr { $$ = new NBinaryOperator(*$1, $2, *$3); }
      | expr TMOD   expr { $$ = new NBinaryOperator(*$1, $2, *$3); }
      | expr TPOW   expr { $$ = new NBinaryOperator(*$1, $2, *$3); }
      ;

%%