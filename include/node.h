#pragma once
#include "stdinc.h"
#include "llvm_include.h"

class CodeGenContext;
class NStatement;
class NExpression;
class NVariableDeclaration;

typedef std::vector<NStatement*> StatementList;
typedef std::vector<NExpression*> ExpressionList;
typedef std::vector<NVariableDeclaration*> VariableList;

class Node {
public:
    virtual ~Node() {}
    virtual llvm::Value* codeGen(CodeGenContext& context) { return nullptr; }
};

class NExpression : public Node {
};

class NStatement : public Node {
};

class NIntConstant : public NExpression {
public:
    const std::string value;
    NIntConstant(const std::string& value) : value(value) { }
    //virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NSringConstant : public NExpression {
public:
    const std::string value;
    NSringConstant(const std::string& value) : value(value) { }
    //virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NDouble : public NExpression {
public:
    double value;
    NDouble(double value) : value(value) { }
    //virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NIdentifier : public NExpression {
public:
    std::string name;
    NIdentifier(const std::string& name) : name(name) { }
    //virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NMethodCall : public NExpression {
public:
    const NIdentifier& id;
    ExpressionList arguments;
    NMethodCall(const NIdentifier& id, ExpressionList& arguments) :
        id(id), arguments(arguments) { }
    NMethodCall(const NIdentifier& id) : id(id) { }
    //virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NBinaryOperator : public NExpression {
public:
    int op;
    NExpression& lhs;
    NExpression& rhs;
    NBinaryOperator(NExpression& lhs, int op, NExpression& rhs) :
        lhs(lhs), rhs(rhs), op(op) { }
    //virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NAssignment : public NExpression {
public:
    NIdentifier& lhs;
    NExpression& rhs;
    NAssignment(NIdentifier& lhs, NExpression& rhs) : 
        lhs(lhs), rhs(rhs) { }
    //virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NBlock : public NExpression {
public:
    StatementList statements;
    NBlock() { }
    //virtual llvm::Value* codeGen(CodeGenContext& context);
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
    //virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NBreakStatement : public NStatement {
public:
    NBreakStatement() { }

    //virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NContinueStatement : public NStatement {
public:
    NContinueStatement() { }

    //virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NReturnStatement : public NStatement {
public:
    NExpression* RetExpr;
    NReturnStatement() { }
    NReturnStatement(NExpression* RetExpr) :
        RetExpr(RetExpr) { }

    //virtual llvm::Value* codeGen(CodeGenContext& context);
};


class NWhileStatement : public NStatement {
public:
    NExpression* Expr;
    NBlock* WhileBlock;
    NWhileStatement(NExpression* Expr, NBlock* WhileBlock) :
        Expr(Expr), WhileBlock(WhileBlock) { }

    //virtual llvm::Value* codeGen(CodeGenContext& context);
};


class NExpressionStatement : public NStatement {
public:
    NExpression& expression;
    NExpressionStatement(NExpression& expression) : 
        expression(expression) { }
    //virtual llvm::Value* codeGen(CodeGenContext& context);
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
    //virtual llvm::Value* codeGen(CodeGenContext& context);
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
    //virtual llvm::Value* codeGen(CodeGenContext& context);
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
};

class NForStatement : public NStatement {
public:
    NVariableDeclaration* VarDecl;
    NIterator* Iter;
    NBlock* ForBlock;
    NForStatement(NVariableDeclaration* VarDecl, NIterator* Iter, NBlock* ForBlock) :
        VarDecl(VarDecl), Iter(Iter), ForBlock(ForBlock) { }

    //virtual llvm::Value* codeGen(CodeGenContext& context);
};