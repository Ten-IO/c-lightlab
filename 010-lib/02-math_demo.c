#include <stdio.h>
#include <math.h>
#include <time.h> 
#include <string.h> 
int main() { 
    // Math functions 
    double x = 4.0; 
    printf("sqrt(%.1f) = %.2f\n", x, sqrt(x)); 
    printf("pow(%.1f, 2) = %.2f\n", x, pow(x, 2)); 
    // Time measurement 
    clock_t start = clock(); 
    for (int i = 0; i < 1000000; i++) {} 
    clock_t end = clock(); 
    printf("Time taken: %.2f seconds\n", (double)(end - start)/CLOCKS_PER_SEC); 
    // String operations 
    char str1[20] = "Hello"; 
    char str2[] = " World!"; 
    strcat(str1, str2); 
    printf("Concatenated string: %s (length: %zu)\n", str1, strlen(str1)); 
    return 0; 
} 