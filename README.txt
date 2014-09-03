# Safe Point instrumentation passes for LLVM
# Brandon Lucia - 2014
########################

This pass inserts calls to extern void __safepoint(void) on loop back edges and
function entries.

########################

Our LLVM passes are built "out of source," meaning you can install LLVM
separately and simply load our passes as modules with LLVM's opt tool.

First build LLVM and install it in /path/to/llvm.

Then, in this directory, run

    $ cmake -DSP_LLVM_DIR=/path/to/llvm .
    $ make

Then you can load the passes into clang and compile with hooks inserted.
