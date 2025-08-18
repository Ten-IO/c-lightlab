#include <stdio.h>
int main() {
    int n, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &n);

    for (int i = n; i <= 1000; i++) {
        if (i == 100) continue;
        sum += i;
    }
    printf("The summation from %d to 1000 except the number 100 is: %d\n", n, sum);
    return 0;
}
