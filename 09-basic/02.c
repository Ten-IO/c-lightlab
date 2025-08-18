#include <stdio.h>
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (num < 0 && num % 2 != 0)
        printf("It is in the category A: negative and odd number.\n");
    else if (num < 0 && num % 2 == 0)
        printf("It is in the category B: negative and even number.\n");
    else if (num > 0 && num % 2 != 0)
        printf("It is in the category C: positive and odd number.\n");
    else if (num > 0 && num % 2 == 0)
        printf("It is in the category D: positive and even number.\n");
    else
        printf("The number is zero, which is neither positive nor negative.\n");
    return 0;
}
