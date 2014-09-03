#include <llvm/Analysis/LoopPass.h>

class BackEdgeSafePoint: public llvm::LoopPass {

    public:

        static char ID;
        BackEdgeSafePoint();
        virtual ~BackEdgeSafePoint();
        virtual const char *getPassName() const;

        virtual bool doInitialization (llvm::Loop *L, llvm::LPPassManager &LPM);
        virtual bool runOnLoop (llvm::Loop *L, llvm::LPPassManager &LPM);
        virtual bool doFinalization ();
        virtual void getAnalysisUsage (llvm::AnalysisUsage &AU) const;

};
