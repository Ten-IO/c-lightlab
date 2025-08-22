`Creating and Using Static Libraries`
1. Use the same files from Exercise 3 
2. Compile math_utils.c with -fPIC flag into object file 
3. Create a shared library (libmathutils.so)
4. Link your main program with the shared library 
5. Set LD_LIBRARY_PATH and run the program 

[++] Modify the math functions and recompile what needs to be recompiled: 
- Recompile the math_utils.c to object file math_utils.o 
- re-create the shared library libmathutils.so (no need to recompile main.c) 
- Relink the executable: compile main.c and link it with the shared library in current working directory to produce an executable 