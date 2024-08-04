%%
program : stmts 
        ;
        
stmts : stmt 
      | stmts stmt 
      ;

stmt : var_decl TSCOLON 
     | func_decl
     | expr TSCOLON 
     | if_stmt
     | for_stmt
     | while_stmt
     | ret_stmt TSCOLON
     | break_stmt TSCOLON
     | continue_stmt TSCOLON
     ;

if_stmt : TIF expr TCOLON block 
        | TIF expr TCOLON stmt 
        | TIF expr TCOLON block TELSE TCOLON block 
        | TIF expr TCOLON stmt TELSE TCOLON block
        | TIF expr TCOLON block TELSE TCOLON stmt
        | TIF expr TCOLON stmt TELSE TCOLON stmt 
        ;

iterator : TRANGE TLPAREN expr TRPAREN 
         | TRANGE TLPAREN expr TCOMMA expr TRPAREN 
         | TRANGE TLPAREN expr TCOMMA expr TCOMMA expr TRPAREN 
         | TLLBRACK expr TCOMMA expr TRRBRACK 
         ;

for_stmt : TFOR simple_var_decl TIN iterator TCOLON block 
         | TFOR simple_var_decl TIN iterator TCOLON stmt 
         ;

while_stmt : TWHILE expr TCOLON block 
           | TWHILE expr TCOLON stmt 
           ;

break_stmt : TBREAK 
           ;

continue_stmt : TCONTINUE 
           ;

ret_stmt : TRET 
         | TRET expr 
         ;

block : TLBRACE stmts TRBRACE 
      | TLBRACE TRBRACE 
      ;

type : ident 
     | type TRARROW ident 
     ;

simple_var_decl : ident TCOLON type 
                ;

var_decl : ident TCOLON type TEQUAL expr 
         | simple_var_decl
         ;
        
func_decl : TFN ident TLPAREN func_decl_args TRPAREN TCOLON type block 
            
          ;

func_decl_args : /*blank*/  
          | var_decl 
          | func_decl_args TCOMMA var_decl 
          ;

ident : TIDENTIFIER 
      ;

cst_string : TCSTSTRING 
           ;

cst_int : TINTEGER 
  //    | TDOUBLE 
        ;
    
expr : ident TEQUAL expr 
     | ident TLPAREN call_args TRPAREN 
     | ident 
     | cst_int
     | cst_string
     | binop
     | TLPAREN expr TRPAREN 
     | TTRUE 
     | TFALSE 
     ;
    
call_args : 
          | expr 
          | call_args TCOMMA expr  
          ;

binop : expr TCEQ   expr 
      | expr TCNE   expr 
      | expr TCLT   expr 
      | expr TCLE   expr 
      | expr TCGT   expr 
      | expr TCGE   expr 
      | expr TPLUS  expr 
      | expr TMINUS expr  
      | expr TMUL   expr 
      | expr TDIV   expr 
      | expr TMOD   expr 
      | expr TPOW   expr 
      ;

%%