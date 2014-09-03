#include "SafePoints.h"
#include "BackEdgeSafePoint.h"
#include "llvm/Support/InstIterator.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/CFG.h"
#include <llvm/Analysis/CallGraph.h>
#include <llvm/Analysis/LoopPass.h>
#include <cstdio>
#include <iostream>

using namespace llvm;

BackEdgeSafePoint::BackEdgeSafePoint() : LoopPass(ID)
{ 
}

BackEdgeSafePoint::~BackEdgeSafePoint ()
{ }

bool BackEdgeSafePoint::doInitialization (Loop *L, LPPassManager &LPM)
{

    return false;
}
        
bool BackEdgeSafePoint::runOnLoop (Loop *L, LPPassManager &LPM)
{

    BasicBlock *H = L->getHeader();
    Function *F = H->getParent();
    Module *M = F->getParent();

    Constant *hookFunc = M->getOrInsertFunction(SPFunctionName, Type::getVoidTy(M->getContext()), (Type*)0);
    Function *SPFunctionPtr = cast<Function>(hookFunc);

    llvm::outs() << "Starting the BackEdge Safe Point Analysis\n";
    Instruction *I = H->getFirstInsertionPt();
    Instruction *callI = CallInst::Create( SPFunctionPtr, "");
    H->getInstList().insert(I,callI);
    return false;

}




void BackEdgeSafePoint::getAnalysisUsage (AnalysisUsage &AU) const
{
  AU.addPreserved<LoopInfo>();

}

bool BackEdgeSafePoint::doFinalization ()
{
    return false;
}

const char *BackEdgeSafePoint::getPassName () const {
    return "DINO Task Boundary Cost Analysis";
}

char BackEdgeSafePoint::ID = 0;

LoopPass *llvm::createBackEdgeSafePoint() {
    return new BackEdgeSafePoint();
}
