#include <stdio.h>
int price[100];
int weight[100];
//#define max(a, b) ((a) > (b) ? (a) : (b))

int max(int i, int j) {
    return (i > j) ? i : j;
}

int main() {
//    printf("Enter the number of items: ");
//    int n;
//    scanf("%d", &n);
//    printf("Enter the maximum bag size: ");
//    int W;
//    scanf("%d", &W);
//
//    printf("Enter the value of items: ");
//    for (int i = 1; i <= n; ++i) {
//        scanf(" %d", &price[i]);
//    }
//    printf("Enter the value of bag sizes: ");
//    for (int i = 1; i <= n; ++i) {
//        scanf(" %d", &weight[i]);
//    }
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening input file");
        return 0;
    }
    int n, W;

    fscanf(file, "%d", &n);

    fscanf(file, "%d", &W);

    for (int i = 1; i <=n; ++i) {
        fscanf(file, "%d", &price[i]);
    }

    for (int i = 1; i <= n; ++i) {
        fscanf(file, "%d", &weight[i]);
    }

    fclose(file);

    int p[n+1][W+1];
    for (int i = 0; i <= n; ++i) {
        p[i][0] = 0;
    }
    for (int w = 0; w <= W; ++w) {
        p[0][w] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if(weight[i] > w){
                p[i][w] = p[i-1][w];
            } else{
                p[i][w] = max(price[i]+p[i-1][w-weight[i]], p[i-1][w]);
            }
        }
    }
    printf("Maximum profit is: %d", p[n][W]);
    return 0;
}
