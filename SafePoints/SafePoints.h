#ifndef _________________DINO_H__
#define _________________DINO_H__

#include <llvm/Pass.h>
#include <llvm/IR/Instruction.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/Analysis/Dominators.h>
#include <llvm/Analysis/PostDominators.h>
#include <llvm/Analysis/LoopInfo.h>
#include <llvm/Analysis/LoopPass.h>
#include <map>
#include <set>

namespace llvm {
    llvm::LoopPass *createBackEdgeSafePoint();
    llvm::FunctionPass *createFuncEntrySafePoint();
}
extern const char *SPFunctionName;

#endif // _________________DINO_H__
