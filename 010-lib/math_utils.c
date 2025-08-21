#include "math_utils.h"

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
float divide(int a, int b) { return (b != 0) ? (float)a / b : 0; }
int mod(int a, int b) { return a % b; }
