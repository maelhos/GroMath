#include "JIT.h"

GroMathJIT::GroMathJIT(std::unique_ptr<llvm::orc::ExecutionSession> ES,
              llvm::orc::JITTargetMachineBuilder JTMB, llvm::DataLayout DL)
        : ES(std::move(ES)), DL(std::move(DL)), Mangle(*this->ES, this->DL),
          ObjectLayer(*this->ES,
                      []() { return std::make_unique<llvm::SectionMemoryManager>(); }),
          CompileLayer(*this->ES, ObjectLayer,
                       std::make_unique<llvm::orc::ConcurrentIRCompiler>(std::move(JTMB))),
          MainJD(this->ES->createBareJITDylib("<main>")) {

        MainJD.addGenerator(
            cantFail(llvm::orc::DynamicLibrarySearchGenerator::GetForCurrentProcess(
                DL.getGlobalPrefix())));

        if (JTMB.getTargetTriple().isOSBinFormatCOFF()) {
            ObjectLayer.setOverrideObjectFlagsWithResponsibilityFlags(true);
            ObjectLayer.setAutoClaimResponsibilityForObjectSymbols(true);
        }
    }

llvm::Expected<std::unique_ptr<GroMathJIT>> GroMathJIT::Create() {
    auto EPC = llvm::orc::SelfExecutorProcessControl::Create();
    if (!EPC)
        return EPC.takeError();

    auto ES = std::make_unique<llvm::orc::ExecutionSession>(std::move(*EPC));

    llvm::orc::JITTargetMachineBuilder JTMB(
        ES->getExecutorProcessControl().getTargetTriple());

    auto DL = JTMB.getDefaultDataLayoutForTarget();
    if (!DL)
        return DL.takeError();

    return std::make_unique<GroMathJIT>(std::move(ES), std::move(JTMB), std::move(*DL));
}

GroMathJIT::~GroMathJIT() {
    if (auto Err = ES->endSession())
        ES->reportError(std::move(Err));
}

const llvm::DataLayout& GroMathJIT::getDataLayout() const { return DL; }

llvm::orc::JITDylib& GroMathJIT::getMainJITDylib() { return MainJD; }

llvm::Error GroMathJIT::addModule(llvm::orc::ThreadSafeModule TSM, llvm::orc::ResourceTrackerSP RT) {
    if (!RT)
        RT = MainJD.getDefaultResourceTracker();
    return CompileLayer.add(RT, std::move(TSM));
}

llvm::Expected<llvm::orc::ExecutorSymbolDef> GroMathJIT::lookup(llvm::StringRef Name) {
    return ES->lookup({&MainJD}, Mangle(Name.str()));
}