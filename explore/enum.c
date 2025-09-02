#include <stdio.h>

enum Role
{
    admin = 1,
    staff = 2,
};

int main()
{
    enum Role r = admin;
    if (r == 1)
        printf("+ Full access from type int enum\n");
    else if (r == 2)
        printf("Partial Access");
    else
        printf("View only");

    if (r == admin)
        printf("- Full access from type str enum\n");
    else if (r == 2)
        printf("Partial Access");
    else
        printf("View only");
}