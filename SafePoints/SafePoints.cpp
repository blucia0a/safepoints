#include <string.h>
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instruction.h"
#include "llvm/IR/Instructions.h"
#include "llvm/PassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Support/InstIterator.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/raw_ostream.h"
#include "SafePoints.h"

using namespace llvm;

const char *SPFunctionName = "__safepoint";

namespace {
    static void registerDINO (const llvm::PassManagerBuilder &, llvm::PassManagerBase &PM) {
        PM.add(llvm::createBackEdgeSafePoint());
        PM.add(llvm::createFuncEntrySafePoint());
    }

    // Run DINO pass after all other optimizations.
    static llvm::RegisterStandardPasses
        RegisterDINO(llvm::PassManagerBuilder::EP_OptimizerLast, registerDINO);
}
