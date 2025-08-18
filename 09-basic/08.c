#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    char fname[50], lname[50], username[100];
    printf("Enter your first name: ");
    scanf("%s", fname);
    printf("Enter your last name: ");
    scanf("%s", lname);

    strcpy(username, fname);
    strcat(username, "_");
    strcat(username, lname);
    for (int i = 0; username[i]; i++) 
        username[i] = tolower(username[i]);
    printf("A. Concatenation: %s\n", username);
    printf("B. Lengths - First name: %lu, Last name: %lu\n", strlen(fname), strlen(lname));
    printf("C. First char of last name: %c, Last char of first name: %c\n", lname[0], fname[strlen(fname) - 1]);
    return 0;
}
