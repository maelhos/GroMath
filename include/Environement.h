#pragma once
#include "stdinc.h"
#include "logger.h"

class Environement : public std::enable_shared_from_this<Environement> {

public:
    Environement(std::map<std::string, llvm::Value*> record,
                std::shared_ptr<Environement> parent)
                : record_(record), parent_(parent) {};

    llvm::Value* define(const std::string& name, llvm::Value* val) {
        record_[name] = val;
        return val;
    }

    llvm::Value* lookup(const std::string& name) {
        return resolve(name)->record_[name];
    }

private:
    std::shared_ptr<Environement> resolve(const std::string& name) {
        if (record_.count(name) != 0)
            return shared_from_this();

        if (parent_ == nullptr)
            DIE << "Variable \"" << name << "\" is not defined." << std::endl;
        
        return parent_->resolve(name);
    }

    std::shared_ptr<Environement> parent_;
    std::map<std::string, llvm::Value*> record_;

};

