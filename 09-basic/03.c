#include <stdio.h>
int main() {
    int nums[10], i, max, min;
    for (i = 0; i < 10; i++) {
        printf("Enter number #%d: ", i + 1);
        scanf("%d", &nums[i]);
    }
    max = min = nums[0];
    for (i = 1; i < 10; i++) {
        if (nums[i] > max) max = nums[i];
        if (nums[i] < min) min = nums[i];
    }
    printf("Among the numbers, the max is %d and the min is %d\n", max, min);
    return 0;
}
