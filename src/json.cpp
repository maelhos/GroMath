#include "node.h"

std::string NIntConstant::toJsonStr(){
    return "{\"type\": \"expression\", \"token\" : \"integer\", \"value\" : " + value + "}";
}

std::string NSringConstant::toJsonStr(){
    return "{\"type\": \"expression\", \"token\" : \"string\", \"value\" : \"" + value + "\"}";
}

std::string NDouble::toJsonStr(){
    return "{\"type\": \"expression\", \"token\" : \"double\", \"value\" : " + std::to_string(value) + "}";
}

std::string NBool::toJsonStr(){
    return "{\"type\": \"expression\", \"token\" : \"bool\", \"value\" : " + std::to_string(value) + "}";
}

std::string NIdentifier::toJsonStr(){
    return "{\"type\": \"expression\", \"token\" : \"identifier\", \"value\" : \"" + name + "\"}";
}

std::string NMethodCall::toJsonStr(){
    std::string res = "{\"type\": \"expression\", \"token\" : \"method\", \"id\" : \"" + id.toJsonStr() + "\", \"arguments\": [";
    for (int i = 0; i < arguments.size(); i++) {
        res += arguments[i]->toJsonStr();

        if (i != arguments.size() - 1)
            res += ", ";
    }
    res += "]}";
    return res;
}

std::string NBinaryOperator::toJsonStr(){
    return "{\"type\" : \"expression\", \"token\" : \"operator\", \"op\" : " + std::to_string(op) 
        + ", \"lhs\" : " + lhs.toJsonStr() + ", \"rhs\" : " + rhs.toJsonStr() + "}";
}

std::string NAssignment::toJsonStr(){
    return "{\"type\" : \"expression\", \"token\" : \"assignment\", \"lhs\" : " 
        + lhs.toJsonStr() + ", \"rhs\" : " + rhs.toJsonStr() + "}";
}

std::string NBlock::toJsonStr(){
    std::string res = "{\"type\" : \"expression\", \"token\" : \"block\", \"statements\" : [";
    for (int i = 0; i < statements.size(); i++) {
        res += statements[i]->toJsonStr();

        if (i != statements.size() - 1)
            res += ", ";
    }
    res += "]}";
    return res;
}

std::string NIfStatement::toJsonStr(){
    return "{\"type\" : \"statement\", \"token\" : \"if\", \"condition\" : " 
        + conditionExpr->toJsonStr() + ", \"ifblock\" : " 
        + IfBlock->toJsonStr() + ", \"elseblock\" : " + ElseBlock->toJsonStr() + "}";
}

std::string NBreakStatement::toJsonStr(){
    return "{\"type\" : \"statement\", \"token\" : \"break\"}";
}

std::string NContinueStatement::toJsonStr(){
    return "{\"type\" : \"statement\", \"token\" : \"continue\"}";
}

std::string NReturnStatement::toJsonStr(){
    return "{\"type\" : \"statement\", \"token\" : \"return\", \"returnExpr\" : " + RetExpr->toJsonStr() + "}";
}

std::string NWhileStatement::toJsonStr(){
    return "{\"type\" : \"statement\", \"token\" : \"while\", \"condition\" : " + Expr->toJsonStr() 
        + ", \"block\" : " + WhileBlock->toJsonStr() + "}";
}

std::string NExpressionStatement::toJsonStr(){
    return "{\"type\" : \"statement\", \"token\" : \"expression\", \"expr\" : " + expression.toJsonStr() + "}";
}

std::string NVariableDeclaration::toJsonStr(){
    std::string res = "{\"type\" : \"statement\", \"token\" : \"variableDeclaration\", \"id\" : " + id.toJsonStr() + ", \"type\" : [";
    for (int i = 0; i < type.size(); i++) {
        res += type[i]->toJsonStr();

        if (i != type.size() - 1)
            res += ", ";
    }
    
    if (assignmentExpr)
        res += "], \"expression\" : " + assignmentExpr->toJsonStr() + "}";
    else
        res += "]}";
        
    return res;
}

std::string NFunctionDeclaration::toJsonStr(){
    std::string res = "{\"type\" : \"statement\", \"token\" : \"functionDeclaration\", \"id\" : " + id.toJsonStr() 
        + ", \"type\" : ["; 
    
    for (int i = 0; i < retType->size(); i++) {
        res += retType->at(i)->toJsonStr();

        if (i != retType->size() - 1)
            res += ", ";
    }

    res += "], \"arguments\" : [";
    for (int i = 0; i < arguments.size(); i++) {
        res += arguments[i]->toJsonStr();

        if (i != arguments.size() - 1)
            res += ", ";
    }
    res += "], \"block\" : " + block.toJsonStr() + "}";
    return res;
}

std::string NRangeIterator::toJsonStr(){
    return "{\"type\" : \"expression\", \"token\" : \"iterator\", \"start\" : " + start->toJsonStr() 
        + ", \"stop\" : " + stop->toJsonStr() 
        + ", \"incr\" : " + incr->toJsonStr() + ", \"end\" : " + std::to_string(endInclusive) + "}";
}

std::string NForStatement::toJsonStr(){
    return "{\"type\" : \"statement\", \"token\" : \"for\", \"declaration\" : " + VarDecl->toJsonStr() 
        + ", \"iter\" : " + Iter->toJsonStr() + ", \"block\" : " + ForBlock->toJsonStr() + "}";
}