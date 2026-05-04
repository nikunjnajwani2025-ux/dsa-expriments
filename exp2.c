#include <stdio.h>
int sumRecursive(int a[], int n) {
    if (n == 0)
        return 0;
    else
        return a[n-1] + sumRecursive(a, n-1);
}

int main() {
    int n, i;
    int a[100];
    int sum_iter = 0, sum_rec;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++) {
        sum_iter = sum_iter + a[i];
    }
    sum_rec = sumRecursive(a, n);

    printf("\nSum using iteration = %d\n", sum_iter);
    printf("Sum using recursion = %d\n", sum_rec);

    return 0;
}
