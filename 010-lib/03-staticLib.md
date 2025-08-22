`Creating and Using Static Libraries`
1. Write three files in C using vim : 
    - math_utils.c (include header file and implementations of basic math operations: add, subtract, multiply, divide functions) 
    - math_utils.h (header with function declarations: add, subtract, multiply, divide functions) 
    - main.c (program that uses the math functions and include the header file) 
2. Compile math_utils.c into an object file 
3. Create a static library (libmathutils.a) by archiving the object file 
4. Link and use the static library libmathutils.a in your main program
5. Run

[++] Modify the math functions and recompile what needs to be recompiled: 
- Add modulous function definition in math_utils.c  
- Add modulous function declaration in math_utils.h 
- Recompile the math_utils.c to object file 
- Re-archive/re-create the static library 
- Add a line to use the modulous in the main.c 
- Relink main.c to the library (no need to recompile main.c to object file)