#include <stdio.h>
int price[100];
int weight[100];

int max(int i, int j) {
    return (i > j) ? i : j;
}

void printSelectedItems(int n, int w, int p[][100]) {
    if(n==0 || w==0)
        return;
    if(p[n][w] != p[n-1][w]){

        printSelectedItems(n-1, w-weight[n], p);
        printf("%d ", n);
    }
    else {
        printSelectedItems(n - 1, w, p);
    }
}

int main() {
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
    int items[n+1];
    for (int i = 0; i <= n; ++i) {
        items[i] = 0;
    }

    printf("Selected items: ");
    printSelectedItems(n, W, p);

    printf("\nMaximum profit is: %d", p[n][W]);
    return 0;
}
