/*
    [+] A C program to compute 5 basic mathematical operations between two input 
        numbers a and b. The 4 operations are: addition, subtraction, multiplication, division 
        and modulo. 
*/
#include <stdio.h>
int main() {
    int a, b;
    printf("Enter a: ");
    scanf("%d", &a);
    printf("Enter b: ");
    scanf("%d", &b);
    printf("Sum (+): %d + %d = %d\n", a, b, a + b);
    printf("Sub - : %d - %d = %d\n", a, b, a - b);
    printf("Mul x: %d * %d = %d\n", a, b, a * b);
    printf("Division: %d / %d = %.2f, and Modulo: %d%% %d = %d\n", a, b, (float)a / b, a, b, a % b);
    return 0;
}