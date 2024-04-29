#pragma once
#include "stdinc.h"
#include "llvm_include.h"

class CodeGenContext {};
class NStatement;
class NExpression;
class NVariableDeclaration;

typedef std::vector<NStatement*> StatementList;
typedef std::vector<NExpression*> ExpressionList;
typedef std::vector<NVariableDeclaration*> VariableList;

class Node {
public:
    virtual ~Node() {}
    virtual llvm::Value* codeGen(CodeGenContext& context) = 0; 
    virtual std::string toJsonStr() = 0;
};

class NExpression : public Node {
};

class NStatement : public Node {
};

class NIntConstant : public NExpression {
public:
    const std::string value;
    NIntConstant(const std::string& value) : value(value) { }

    llvm::Value* codeGen(CodeGenContext& context) override;
    std::string toJsonStr() override;
};

class NSringConstant : public NExpression {
public:
    const std::string value;
    NSringConstant(const std::string& value) : value(value) { }

    llvm::Value* codeGen(CodeGenContext& context);
    std::string toJsonStr();
};

class NDouble : public NExpression {
public:
    double value;
    NDouble(double value) : value(value) { }

    llvm::Value* codeGen(CodeGenContext& context);
    std::string toJsonStr();
};

class NIdentifier : public NExpression {
public:
    std::string name;
    NIdentifier(const std::string& name) : name(name) { }

    llvm::Value* codeGen(CodeGenContext& context);
    std::string toJsonStr();
};

class NMethodCall : public NExpression {
public:
    const NIdentifier& id;
    ExpressionList arguments;
    NMethodCall(const NIdentifier& id, ExpressionList& arguments) :
        id(id), arguments(arguments) { }
    NMethodCall(const NIdentifier& id) : id(id) { }

    llvm::Value* codeGen(CodeGenContext& context);
    std::string toJsonStr();
};

class NBinaryOperator : public NExpression {
public:
    int op;
    NExpression& lhs;
    NExpression& rhs;
    NBinaryOperator(NExpression& lhs, int op, NExpression& rhs) :
        lhs(lhs), rhs(rhs), op(op) { }

    llvm::Value* codeGen(CodeGenContext& context);
    std::string toJsonStr();
};

class NAssignment : public NExpression {
public:
    NIdentifier& lhs;
    NExpression& rhs;
    NAssignment(NIdentifier& lhs, NExpression& rhs) : 
        lhs(lhs), rhs(rhs) { }

    llvm::Value* codeGen(CodeGenContext& context);
    std::string toJsonStr();
};

class NBlock : public NExpression {
public:
    StatementList statements;
    NBlock() { }

    llvm::Value* codeGen(CodeGenContext& context);
    std::string toJsonStr();
};

class NIfStatement : public NStatement {
public:
    NExpression* conditionExpr;
    NBlock* IfBlock;
    NBlock* ElseBlock;
    NIfStatement(NExpression* conditionExpr, NBlock* IfBlock) :
        conditionExpr(conditionExpr), IfBlock(IfBlock), ElseBlock(0) { }
    NIfStatement(NExpression* conditionExpr, NBlock* IfBlock, NBlock* ElseBlock) :
        conditionExpr(conditionExpr), IfBlock(IfBlock), ElseBlock(ElseBlock) { }

    llvm::Value* codeGen(CodeGenContext& context);
    std::string toJsonStr();
};

class NBreakStatement : public NStatement {
public:
    NBreakStatement() { }

    llvm::Value* codeGen(CodeGenContext& context);
    std::string toJsonStr();
};

class NContinueStatement : public NStatement {
public:
    NContinueStatement() { }

    llvm::Value* codeGen(CodeGenContext& context);
    std::string toJsonStr();
};

class NReturnStatement : public NStatement {
public:
    NExpression* RetExpr;
    NReturnStatement() { }
    NReturnStatement(NExpression* RetExpr) :
        RetExpr(RetExpr) { }

    llvm::Value* codeGen(CodeGenContext& context);
    std::string toJsonStr();
};


class NWhileStatement : public NStatement {
public:
    NExpression* Expr;
    NBlock* WhileBlock;
    NWhileStatement(NExpression* Expr, NBlock* WhileBlock) :
        Expr(Expr), WhileBlock(WhileBlock) { }

    llvm::Value* codeGen(CodeGenContext& context);
    std::string toJsonStr();
};


class NExpressionStatement : public NStatement {
public:
    NExpression& expression;
    NExpressionStatement(NExpression& expression) : 
        expression(expression) { }
    llvm::Value* codeGen(CodeGenContext& context);
    std::string toJsonStr();
};

class NVariableDeclaration : public NStatement {
public:
    ExpressionList& type;
    NIdentifier& id;
    NExpression* assignmentExpr;
    NVariableDeclaration(ExpressionList& type, NIdentifier& id) :
        type(type), id(id) { }
    NVariableDeclaration(ExpressionList& type, NIdentifier& id, NExpression* assignmentExpr) :
        type(type), id(id), assignmentExpr(assignmentExpr) { }
    llvm::Value* codeGen(CodeGenContext& context);
    std::string toJsonStr();
};

class NFunctionDeclaration : public NStatement {
public:
    NIdentifier& type;
    const NIdentifier& id;
    VariableList arguments;
    NBlock& block;
    NFunctionDeclaration(NIdentifier& type, const NIdentifier& id, 
            const VariableList& arguments, NBlock& block) :
        type(type), id(id), arguments(arguments), block(block) { }
    llvm::Value* codeGen(CodeGenContext& context);
    std::string toJsonStr();
};

class NIterator : public NExpression {};

class NRangeIterator : public NIterator {
public:
    NExpression* start;
    NExpression* stop;
    NExpression* incr;
    bool endInclusive;

    NRangeIterator(NExpression* start, bool inclusive = false) : 
        start(start), stop(0), incr(0), endInclusive(inclusive) { }
    NRangeIterator(NExpression* start, NExpression* stop, bool inclusive = false) : 
        start(start), stop(stop), incr(0), endInclusive(inclusive) { }
    NRangeIterator(NExpression* start, NExpression* stop, NExpression* incr, bool inclusive = false) : 
        start(start), stop(stop), incr(incr), endInclusive(inclusive) { }

    llvm::Value* codeGen(CodeGenContext& context);
    std::string toJsonStr();
};

class NForStatement : public NStatement {
public:
    NVariableDeclaration* VarDecl;
    NIterator* Iter;
    NBlock* ForBlock;
    NForStatement(NVariableDeclaration* VarDecl, NIterator* Iter, NBlock* ForBlock) :
        VarDecl(VarDecl), Iter(Iter), ForBlock(ForBlock) { }

    llvm::Value* codeGen(CodeGenContext& context);
    std::string toJsonStr();
};