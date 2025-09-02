#include <stdio.h>

char name[20]="Gang C";
int main() {
    int num, charCount;
    // Global words
    printf("Global - %s \n", name);

    // input
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("result: %.2d ", num);

    // Check other value
    printf("addr: %p\n\n", &num);
    printf("void addr: %p\n\n", (void*)&num);
    printf("addr hex: %#x\n\n", &num);

    // test %n
    printf("abc%n \n", &charCount);
    printf("printed char so far: %d", num );
    printf("printed char so far: %d", charCount);
    return 0;
}