#include <stdio.h>
#include <stdlib.h>

// to checkout
int main() {
    char str[3][4] = {"lam","fol", "da", "ka"}; //row 4 load warning out-of-bound, display sort of addr.
    char * ptr =(char*)malloc(4*sizeof(char*));
    char * pstr[3][4] = {"lam","fol", "da", "ka"};

    printf("str: %s\n",str[2] );

    printf("1-arr addr: %s\n", *pstr[0]);
    printf("2-arr addr: %s\n", *pstr[1]);

    printf("to access 2-arr addr: %s\n", *pstr);
    printf("addr ptr: %p\n", pstr[1]);
}