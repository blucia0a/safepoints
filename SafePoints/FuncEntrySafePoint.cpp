#include "SafePoints.h"
#include "FuncEntrySafePoint.h"
#include "llvm/Support/InstIterator.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/CFG.h"
#include <llvm/Analysis/CallGraph.h>
#include <cstdio>
#include <iostream>

using namespace llvm;

FuncEntrySafePoint::FuncEntrySafePoint() : FunctionPass(ID)
{ 
}

FuncEntrySafePoint::~FuncEntrySafePoint ()
{ }

bool FuncEntrySafePoint::doInitialization (Function &F)
{

    return false;
}
        
bool FuncEntrySafePoint::runOnFunction (Function &F)
{

    Module *M = F.getParent();
    BasicBlock &B = F.getEntryBlock();

    Constant *hookFunc = M->getOrInsertFunction(SPFunctionName, Type::getVoidTy(M->getContext()), (Type*)0);
    Function *SPFunctionPtr = cast<Function>(hookFunc);

    llvm::outs() << "Starting the FuncEntry Safe Point Analysis\n";
    Instruction *I = B.getFirstInsertionPt();
    Instruction *callI = CallInst::Create( SPFunctionPtr, "");
    B.getInstList().insert(I,callI);
    return false;

}




void FuncEntrySafePoint::getAnalysisUsage (AnalysisUsage &AU) const
{

}

bool FuncEntrySafePoint::doFinalization ()
{
    return false;
}

const char *FuncEntrySafePoint::getPassName () const {
    return "DINO Task Boundary Cost Analysis";
}

char FuncEntrySafePoint::ID = 0;

FunctionPass *llvm::createFuncEntrySafePoint() {
    return new FuncEntrySafePoint();
}
