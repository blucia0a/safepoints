class FuncEntrySafePoint: public llvm::FunctionPass {

    public:

        static char ID;
        FuncEntrySafePoint();
        virtual ~FuncEntrySafePoint();
        virtual const char *getPassName() const;

        virtual bool doInitialization (llvm::Function &F);
        virtual bool runOnFunction (llvm::Function &F);
        virtual bool doFinalization ();
        virtual void getAnalysisUsage (llvm::AnalysisUsage &AU) const;

};
