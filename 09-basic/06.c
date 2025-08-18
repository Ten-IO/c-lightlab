#include <stdio.h>
#include <math.h>
struct Root {
    int status_code;
    float x1;
    float x2;
};
struct Root solveQuadratic(int a, int b, int c) {
    struct Root result;
    float deta = b * b - 4 * a * c;

    if (deta > 0) {
        result.status_code = 2;
        result.x1 = (-b + sqrt(deta)) / (2 * a);
        result.x2 = (-b - sqrt(deta)) / (2 * a);
    } else if (deta == 0) {
        result.status_code = 1;
        result.x1 = result.x2 = -b / (2.0 * a);
    } else {
        result.status_code = 3;
        result.x1 = -b / (2.0 * a);
        result.x2 = sqrt(-deta) / (2.0 * a); 
    }
    return result;
}

int main() {
    int a, b, c;
    printf("Enter coefficients a, b, c: ");
    scanf("%d %d %d", &a, &b, &c);
    struct Root r = solveQuadratic(a, b, c);
    if (r.status_code == 1)
        printf("Double root: x = %.2f\n", r.x1);
    else if (r.status_code == 2)
        printf("Two roots: x1 = %.2f, x2 = %.2f\n", r.x1, r.x2);
    else
        printf("Complex roots: x1 = %.2f + %.2fi, x2 = %.2f - %.2fi\n", r.x1, r.x2, r.x1, r.x2);
    return 0;
}
