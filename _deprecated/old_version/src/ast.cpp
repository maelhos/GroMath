#include "ast.h"

VariableExprAST::VariableExprAST(const std::string& _Name)
     : Name(_Name) {}

BinaryExprAST::BinaryExprAST(char _Op, std::unique_ptr<ExprAST> _LHS, std::unique_ptr<ExprAST> _RHS)
      : Op(_Op), LHS(std::move(_LHS)), RHS(std::move(_RHS)) {}

CallExprAST::CallExprAST(const std::string& Callee, std::vector<std::unique_ptr<ExprAST>> Args)
      : Callee(Callee), Args(std::move(Args)) {}

IfExprAST::IfExprAST(std::unique_ptr<ExprAST> Cond, std::unique_ptr<ExprAST> Then,
              std::unique_ptr<ExprAST> Else)
      : Cond(std::move(Cond)), Then(std::move(Then)), Else(std::move(Else)) {}

ForExprAST::ForExprAST(const std::string& VarName, std::unique_ptr<ExprAST> Start,
             std::unique_ptr<ExprAST> End, std::unique_ptr<ExprAST> Step,
             std::unique_ptr<ExprAST> Body)
    : VarName(VarName), Start(std::move(Start)), End(std::move(End)),
      Step(std::move(Step)), Body(std::move(Body)) {}

PrototypeAST::PrototypeAST(const std::string &Name, NameType Args, Type ret_type)
    : Name(Name), Args(std::move(Args)), ret_type(ret_type) {}

const std::string& PrototypeAST::getName() const { return Name;}

FunctionAST::FunctionAST(std::unique_ptr<PrototypeAST> Proto, std::unique_ptr<ExprAST> Body)
    : Proto(std::move(Proto)), Body(std::move(Body)) {}

std::unique_ptr<ExprAST> LogError(const char *Str){
    fprintf(stderr, "Error: %s\n", Str);
    return nullptr;
}

std::unique_ptr<PrototypeAST> LogErrorP(const char *Str){
    LogError(Str);
    return nullptr;
}