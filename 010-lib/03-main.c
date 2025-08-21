#include <stdio.h>
#include "math_utils.h"
int main() {
    int a = 10, b = 3;
    printf("Add: %d\n", add(a, b));
    printf("Subtract: %d\n", subtract(a, b));
    printf("Multiply: %d\n", multiply(a, b));
    printf("Divide: %.2f\n", divide(a, b));
    printf("Mod: %d\n", mod(a, b));
    return 0;
}
