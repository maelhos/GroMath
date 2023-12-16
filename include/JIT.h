#pragma once
#include "stdinc.h"

class GroMathJIT {
private:
    std::unique_ptr<llvm::orc::ExecutionSession> ES;

    llvm::DataLayout DL;
    llvm::orc::MangleAndInterner Mangle;

    llvm::orc::RTDyldObjectLinkingLayer ObjectLayer;
    llvm::orc::IRCompileLayer CompileLayer;

    llvm::orc::JITDylib &MainJD;

public:
    GroMathJIT(std::unique_ptr<llvm::orc::ExecutionSession> ES,
              llvm::orc::JITTargetMachineBuilder JTMB, llvm::DataLayout DL);

    ~GroMathJIT();

    static llvm::Expected<std::unique_ptr<GroMathJIT>> Create();

    const llvm::DataLayout& getDataLayout() const;

    llvm::orc::JITDylib& getMainJITDylib();

    llvm::Error addModule(llvm::orc::ThreadSafeModule TSM, llvm::orc::ResourceTrackerSP RT = nullptr);

    llvm::Expected<llvm::orc::ExecutorSymbolDef> lookup(llvm::StringRef Name);
};