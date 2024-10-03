#include <stdio.h>
#include <limits.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int cutRodDP(int price[], int n) {
    int dp[n + 1];
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int maxVal = INT_MIN;
        for (int j = 0; j < i; j++) {
            maxVal = max(maxVal, price[j] + dp[i - j - 1]);
        }
        dp[i] = maxVal;
    }

    return dp[n];
}
int main() {
    int price[] = { 1, 5, 8, 9, 10, 12, 17 };
    int size = sizeof(price) / sizeof(price[0]);

    printf("Input price: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", price[i]);
    }
    printf("\n");

    printf("Maximum Obtainable Value is %d\n", cutRodDP(price, size));

    return 0;
}
