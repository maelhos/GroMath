#pragma once
#include <vector>
#include <string>
#include <memory>
#include <map>
#include "../src/stdinc.h"

class AST {
public:
    virtual ~AST() = default;
    virtual llvm::Value* codegen() = 0;
};


class MainAST;
class ObjDeclAST;
class TypeAST;
class BasicTypeAST;
class FunctionTypeAST;
class FnDeclAST;
class FlowOrStmtAST;
class CtrlFlowAST;
class IfAST;
class IfElseAST;
class WhileAST;
class ForAST;
class BlockAST;
class ExprAST;
class FunctionCall;
class ConstExprStr;
class ConstExprInt;
class PreOpAST;
class BinOpAST;
class StatementAST;
class DeclInitStmtAST;
class DeclStmtAST;
class AssignStmtAST;
class PostStmtAST;
class RetStmtAST;
class BreakStmtAST;
class ContinueStmtAST;

class MainAST : public AST {
    std::vector<std::unique_ptr<ObjDeclAST>> ObjDecls;
    std::vector<std::unique_ptr<FnDeclAST>> FnDecls;
public:
    MainAST() : ObjDecls{}, FnDecls{} {}
    void AddObjDecl(std::unique_ptr<ObjDeclAST>& objDecl) { ObjDecls.push_back(std::move(objDecl)); }
    void AddFnDeclAST(std::unique_ptr<FnDeclAST>& fnDecl) { FnDecls.push_back(std::move(fnDecl)); }
    llvm::Value* codegen() override;
};

class ObjDeclAST : public AST {
    std::string name;
    std::map<std::string, std::unique_ptr<TypeAST>> params;
public:
    ObjDeclAST(const std::string& name) : name(name), params{} {}
    void AddParam(const std::string& name, std::unique_ptr<TypeAST>& type){
        if (params.count(name) > 0) {
            printf("Multiple Identifiers with same name in obj declataion (\"%s\") is not allowed\n",
                name.c_str());
            exit(1);
        }
        params[name] = std::move(type);
    }
    llvm::Value* codegen() override;
};

class TypeAST : public AST {};

class BasicTypeAST : public TypeAST {
    std::string name;
public:
    BasicTypeAST(const std::string& name) : name(name) {}
    llvm::Value* codegen() override;    
};

class FunctionTypeAST : public TypeAST {
    std::vector<std::unique_ptr<BasicTypeAST>> paramsType;
    std::unique_ptr<BasicTypeAST> returnType;
public:
    FunctionTypeAST(std::vector<std::unique_ptr<BasicTypeAST>> paramsType, 
        std::unique_ptr<BasicTypeAST>& returnType) 
        : paramsType{}, returnType(std::move(returnType)) {}

    void AddParamType(std::unique_ptr<BasicTypeAST>& paramType){
        paramsType.push_back(std::move(paramType));
    }

    llvm::Value* codegen() override;    
};

class FnDeclAST : public AST {
    std::string name;
    std::map<std::string, std::unique_ptr<TypeAST>> params;
    std::unique_ptr<TypeAST> returnType;
    std::unique_ptr<BlockAST> block;
public:
    FnDeclAST(const std::string& name, std::unique_ptr<BasicTypeAST>& returnType,
        std::unique_ptr<BlockAST>& block) : name(name), params{}, 
        returnType(std::move(returnType)), block(std::move(block)) {}

    void AddParam(const std::string& name, std::unique_ptr<TypeAST>& paramType){
        if (params.count(name) > 0) {
            printf("Multiple Identifiers with same name in function declataion (\"%s\") is not allowed\n",
                name.c_str());
            exit(1);
        }
        params[name] = std::move(paramType);
    }
    llvm::Value* codegen() override;    
};

class FlowOrStmtAST : public AST {};

class CtrlFlowAST : public FlowOrStmtAST {};

class IfAST : public CtrlFlowAST {
    std::unique_ptr<ExprAST> cond;
    std::unique_ptr<BlockAST> ifBlock;
public:
    IfAST(std::unique_ptr<ExprAST>& cond, std::unique_ptr<BlockAST>& ifBlock) :
        cond(std::move(cond)), ifBlock(std::move(ifBlock)) {}

    llvm::Value* codegen() override;    
};

class IfElseAST : public CtrlFlowAST {
    std::unique_ptr<ExprAST> cond;
    std::unique_ptr<BlockAST> ifBlock;
    std::unique_ptr<BlockAST> elseBlock;
public:
    IfElseAST(std::unique_ptr<ExprAST>& cond, std::unique_ptr<BlockAST>& ifBlock,
        std::unique_ptr<BlockAST>& elseBlock) : cond(std::move(cond)),
        ifBlock(std::move(ifBlock)), elseBlock(std::move(elseBlock)) {}

    llvm::Value* codegen() override;    
};

class WhileAST : public CtrlFlowAST {
    std::unique_ptr<ExprAST> cond;
    std::unique_ptr<BlockAST> whileBlock;
public:
    WhileAST(std::unique_ptr<ExprAST>& cond, std::unique_ptr<BlockAST>& whileBlock) :
        cond(std::move(cond)), whileBlock(std::move(whileBlock)) {}

    llvm::Value* codegen() override;    
};

class ForAST : public CtrlFlowAST {
    std::unique_ptr<ExprAST> decl;
    std::unique_ptr<ExprAST> cond;
    std::unique_ptr<ExprAST> incr;
    std::unique_ptr<BlockAST> forBlock;
public:
    ForAST(std::unique_ptr<ExprAST>& decl, std::unique_ptr<ExprAST>& cond,
        std::unique_ptr<ExprAST>& incr, std::unique_ptr<BlockAST>& forBlock) :
        decl(std::move(decl)), cond(std::move(cond)), incr(std::move(incr)),
        forBlock(std::move(forBlock)) {}

    llvm::Value* codegen() override;    
};

class BlockAST : public AST{
    std::vector<std::unique_ptr<FlowOrStmtAST>> stmtsAndFlow;
public:
    BlockAST() : stmtsAndFlow{} {}
    void AddFlowOrStmtAST(std::unique_ptr<FlowOrStmtAST>& paramType) {
        stmtsAndFlow.push_back(std::move(paramType));
    }

    llvm::Value* codegen() override;   
};

class ExprAST : public AST {};

class FunctionCall : public ExprAST{
    std::string name;
    std::vector<std::string> args;
public:
    FunctionCall(const std::string& name) : name(name) {}
    void AddArg(const std::string& arg) {
        args.push_back(arg);
    }

    llvm::Value* codegen() override;   
};

class ConstExprStr : public ExprAST{
    std::string val;
public:
    ConstExprStr(const std::string& val) : val(val) {}

    llvm::Value* codegen() override;   
};

class ConstExprInt : public ExprAST{
    std::string val;
public:
    ConstExprInt(const std::string& val) : val(val) {}

    llvm::Value* codegen() override;   
};

class PreOpAST : public ExprAST{
    std::unique_ptr<ExprAST> expr;
    std::string op;
public:
    PreOpAST(std::unique_ptr<ExprAST>& expr, const std::string& op) :
        expr(std::move(expr)), op(op) {}

    llvm::Value* codegen() override;   
};

class BinOpAST : public ExprAST{
    std::unique_ptr<ExprAST> left;
    std::string op;
    std::unique_ptr<ExprAST> right;
public:
    BinOpAST(std::unique_ptr<ExprAST>& left, const std::string& op, 
        std::unique_ptr<ExprAST>& right) : left(std::move(left)),
        op(op), right(std::move(right)) {}

    llvm::Value* codegen() override;   
};

class StatementAST : public FlowOrStmtAST {};

class DeclInitStmtAST : public StatementAST{
    std::unique_ptr<TypeAST> type;
    std::string name;
    std::unique_ptr<ExprAST> initExpr;
public:
    DeclInitStmtAST(std::unique_ptr<TypeAST>& type, const std::string& name, 
        std::unique_ptr<ExprAST>& initExpr) : type(std::move(type)), name(name),
        initExpr(std::move(initExpr)) {}

    llvm::Value* codegen() override;  

};

class DeclStmtAST : public StatementAST{
    std::unique_ptr<TypeAST> type;
    std::string name;
public:
    DeclStmtAST(std::unique_ptr<TypeAST>& type, const std::string& name) : 
        type(std::move(type)), name(name) {}

    llvm::Value* codegen() override;  

};

class AssignStmtAST : public StatementAST{
    std::string name;
    std::string op;
    std::unique_ptr<ExprAST> assignExpr;
public:
    AssignStmtAST(const std::string& name, const std::string& op, 
        std::unique_ptr<ExprAST>& assignExpr) : name(name), op(op),
        assignExpr(std::move(assignExpr)) {}

    llvm::Value* codegen() override;  

};

class PostStmtAST : public StatementAST{
    std::string name;
    std::string op;
public:
    PostStmtAST(const std::string& name, const std::string& op) : name(name), op(op) {}

    llvm::Value* codegen() override;  
};

class RetStmtAST : public StatementAST{
    std::unique_ptr<ExprAST> retExpr;
public:
    RetStmtAST() : retExpr(nullptr) {}
    RetStmtAST(std::unique_ptr<ExprAST>& retExpr) : retExpr(std::move(retExpr)) {}

    llvm::Value* codegen() override;  
};

class BreakStmtAST : public StatementAST{
public:
    BreakStmtAST() {}

    llvm::Value* codegen() override;  
};

class ContinueStmtAST : public StatementAST{
public:
    ContinueStmtAST() {}

    llvm::Value* codegen() override;  
};