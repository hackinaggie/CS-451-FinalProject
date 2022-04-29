# CSCE 451 Final Project

This repository contains the work for the **14-VTTF** reversing team consisting of *Vicente Tovar-Marquez* and *Terrell Ford*. Both source directories contain a makefile. Use `make all` to compile the source code to a binary. Use `make run` to run it. Lastly, use `make clean` to remove all the binary and object files from the folder.


The [ghidra](./ghidra) directory contains both the original (original.bin) and working modified binary (working.bin). It also includes the Ghidra export file that we have exported from Ghidra (ghidra_exp.gzf). That file can be imported into your local Ghidra program to see all the modifications and renaming that we have done on the binary.


The [inGen_1.0_src](./inGen_1.0_src) directory contains the **ORIGINAL** reversed source code that we've derived from the binary. This source code and resulting binary contains all the dead code, vulnerable function calls, and bloatware contained in the original binary.


The [inGen_2.0_src](./inGen_2.0_src) directory contains the **NEW** reversed source code that was modified from the inGen_1.0 source. We did things like use secure function calls, remove dead code that includes `Hash`, `MyItem`, `Fence` classes and while loops. 

By updating the code, we were able to make the final inGen2.0 binary a total of **22,632** bytes smaller!
