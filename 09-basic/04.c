#include <stdio.h>
int main() {
    int sum = 0, sub = 0;
    for (int i = 500; i >= 10; i--) {
        sum += i;
        sub -= i;
    }
    printf("The summation: 500 + 499 + ... + 10 = %d\n", sum);
    printf("The subtraction: -500 - 499 - ... - 10 = %d\n", sub);
    return 0;
}
