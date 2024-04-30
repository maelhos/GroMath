#include "node.h"

std::string NIntConstant::toJsonStr(){
    return "{'type': 'expression', 'token' : 'integer', 'value' : " + this->value + "}";
}

std::string NSringConstant::toJsonStr(){
    return "{'type': 'expression', 'token' : 'string', 'value' : '" + this->value + "'}";
}

std::string NDouble::toJsonStr(){
    return "{'type': 'expression', 'token' : 'double', 'value' : " + std::to_string(this->value) + "}";
}

std::string NIdentifier::toJsonStr(){
    return "{'type': 'expression', 'token' : 'identifier', 'value' : '" + this->name + "'}";
}

std::string NMethodCall::toJsonStr(){
    std::string res = "{'type': 'expression', 'token' : 'method', 'id' : '" + id.toJsonStr() + "', 'arguments': [";
    for (auto expr : arguments) {
        res += expr->toJsonStr();
        res += ',';
    }
    res += "]}";
    return res;
}

std::string NBinaryOperator::toJsonStr(){
    return "{'type' : 'expression', 'token' : 'operator', 'op' : " + std::to_string(op) + ", 'lhs' : " + lhs.toJsonStr() + ", 'rhs' : " + rhs.toJsonStr() + "}";
}

std::string NAssignment::toJsonStr(){
    return "{'type' : 'expression', 'token' : 'assignment', 'lhs' : " + lhs.toJsonStr() + ", 'rhs' : " + rhs.toJsonStr() + "}";
}

std::string NBlock::toJsonStr(){
    std::string res = "{'type' : 'expression', 'token' : 'block', 'statements' : [";
    for (auto statement : statements) {
        res += statement->toJsonStr();
        res += ', ';
    }
    res += "]}";
    return res;
}

std::string NIfStatement::toJsonStr(){
    return nullptr;
}

std::string NBreakStatement::toJsonStr(){
    return nullptr;
}

std::string NContinueStatement::toJsonStr(){
    return nullptr;
}

std::string NReturnStatement::toJsonStr(){
    return nullptr;
}

std::string NWhileStatement::toJsonStr(){
    return nullptr;
}

std::string NExpressionStatement::toJsonStr(){
    return nullptr;
}

std::string NVariableDeclaration::toJsonStr(){
    return nullptr;
}

std::string NFunctionDeclaration::toJsonStr(){
    return nullptr;
}

std::string NRangeIterator::toJsonStr(){
    return nullptr;
}

std::string NForStatement::toJsonStr(){
    return nullptr;
}