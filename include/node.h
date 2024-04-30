#pragma once
#include "stdinc.h"
#include "llvm_include.h"
#include "Environement.h"

struct GMLLVM;
class NStatement;
class NExpression;
class NVariableDeclaration;

using StatementList = std::vector<NStatement*>;
using ExpressionList = std::vector<NExpression*>;
using VariableList = std::vector<NVariableDeclaration*>;

class Node {
public:
    virtual ~Node() {}
    virtual llvm::Value* codeGen(GMLLVM* context) = 0; 
    virtual std::string toJsonStr() = 0;
};

class NExpression : public Node {};
class NStatement : public Node {};
class NBlock : public NExpression {
public:
    StatementList statements;
    NBlock() { }

    llvm::Value* codeGen(GMLLVM* context);
};


class NIntConstant : public NExpression {
public:
    const std::string value;
    NIntConstant(const std::string& value) : value(value) { }

    llvm::Value* codeGen(GMLLVM* context) override;
    std::string toJsonStr() override;
};

class NSringConstant : public NExpression {
public:
    const std::string value;
    NSringConstant(const std::string& value) : value(value) { }

    llvm::Value* codeGen(GMLLVM* context) override;
    std::string toJsonStr() override;
};

class NDouble : public NExpression {
public:
    double value;
    NDouble(double value) : value(value) { }

    llvm::Value* codeGen(GMLLVM* context) override;
    std::string toJsonStr() override;
};

class NIdentifier : public NExpression {
public:
    std::string name;
    NIdentifier(const std::string& name) : name(name) { }

    llvm::Value* codeGen(GMLLVM* context) override;
    std::string toJsonStr() override;
};

class NMethodCall : public NExpression {
public:
    const NIdentifier& id;
    ExpressionList arguments;
    NMethodCall(const NIdentifier& id, ExpressionList& arguments) :
        id(id), arguments(arguments) { }
    NMethodCall(const NIdentifier& id) : id(id) { }

    llvm::Value* codeGen(GMLLVM* context) override;
    std::string toJsonStr() override;
};

class NBinaryOperator : public NExpression {
public:
    int op;
    NExpression& lhs;
    NExpression& rhs;
    NBinaryOperator(NExpression& lhs, int op, NExpression& rhs) :
        lhs(lhs), rhs(rhs), op(op) { }

    llvm::Value* codeGen(GMLLVM* context) override;
    std::string toJsonStr() override;
};

class NAssignment : public NExpression {
public:
    NIdentifier& lhs;
    NExpression& rhs;
    NAssignment(NIdentifier& lhs, NExpression& rhs) : 
        lhs(lhs), rhs(rhs) { }

    llvm::Value* codeGen(GMLLVM* context) override;
    std::string toJsonStr() override;
};

class NBlock : public NExpression {
public:
    StatementList statements;
    NBlock() { }

    llvm::Value* codeGen(GMLLVM* context);
    std::string toJsonStr() override;
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

    llvm::Value* codeGen(GMLLVM* context) override;
    std::string toJsonStr() override;
};

class NBreakStatement : public NStatement {
public:
    NBreakStatement() { }

    llvm::Value* codeGen(GMLLVM* context) override;
    std::string toJsonStr() override;
};

class NContinueStatement : public NStatement {
public:
    NContinueStatement() { }

    llvm::Value* codeGen(GMLLVM* context) override;
    std::string toJsonStr() override;
};

class NReturnStatement : public NStatement {
public:
    NExpression* RetExpr;
    NReturnStatement() { }
    NReturnStatement(NExpression* RetExpr) :
        RetExpr(RetExpr) { }

    llvm::Value* codeGen(GMLLVM* context) override;
    std::string toJsonStr() override;
};


class NWhileStatement : public NStatement {
public:
    NExpression* Expr;
    NBlock* WhileBlock;
    NWhileStatement(NExpression* Expr, NBlock* WhileBlock) :
        Expr(Expr), WhileBlock(WhileBlock) { }

    llvm::Value* codeGen(GMLLVM* context) override;
    std::string toJsonStr() override;
};


class NExpressionStatement : public NStatement {
public:
    NExpression& expression;
    NExpressionStatement(NExpression& expression) : 
        expression(expression) { }
    llvm::Value* codeGen(GMLLVM* context) override;
    std::string toJsonStr() override;
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
    llvm::Value* codeGen(GMLLVM* context) override;
    std::string toJsonStr() override;
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
    llvm::Value* codeGen(GMLLVM* context) override;
    std::string toJsonStr() override;
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

    llvm::Value* codeGen(GMLLVM* context) override;
    std::string toJsonStr() override;
};

class NForStatement : public NStatement {
public:
    NVariableDeclaration* VarDecl;
    NIterator* Iter;
    NBlock* ForBlock;
    NForStatement(NVariableDeclaration* VarDecl, NIterator* Iter, NBlock* ForBlock) :
        VarDecl(VarDecl), Iter(Iter), ForBlock(ForBlock) { }

    llvm::Value* codeGen(GMLLVM* context) override;
    std::string toJsonStr() override;
};

extern NBlock* programBlock;