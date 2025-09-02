#include <stdio.h>

int add(int x, int y); // with param
int add(int, int);

int main() {
    int result = add(3,5);
    printf("sum: %d\n", result);
}

int add(int x, int y){
    return x+y;
}