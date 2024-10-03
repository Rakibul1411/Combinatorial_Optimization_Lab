#include <stdio.h>
#include <limits.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}


int cutRod(int price[], int index, int n, int* rod_sizes) {

    if (index == 0) {
        return n * price[0];
    }

    int notCut = cutRod(price, index - 1, n, rod_sizes);
    int cut = INT_MIN;
    int rod_length = index + 1;

    if (rod_length <= n)
        cut = price[index] + cutRod(price, index, n - rod_length, rod_sizes);

    int max_profit = max(notCut, cut);

    if (max_profit == cut) {
        rod_sizes[n] = rod_length;
    }

    return max_profit;
}

int main() {
    int pricre[] = { 1, 5, 8, 9, 10, 12, 17 };
    int size = sizeof(pricre) / sizeof(pricre[0]);

    int rod_sizes[size + 1];
    for (int i = 0; i <= size; i++) {
        rod_sizes[i] = -1;
    }

    printf("Input array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", pricre[i]);
    }
    printf("\n");

    printf("Maximum Obtainable Value is %d\n", cutRod(pricre, size - 1, size, rod_sizes));

    printf("Rod sizes for maximum profit: ");
    for (int i = size; i > 0;) {
        if (rod_sizes[i] != -1) {
            printf("%d ", rod_sizes[i]);
            i -= rod_sizes[i];
        } else {
            i--;
        }
    }
    printf("\n");

    return 0;
}
