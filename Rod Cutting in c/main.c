#include <stdio.h>
#define MAX_VALUES 100
int max(int i, int j);

void cutting_length(int size, int n, int c[][MAX_VALUES], int rod[]) {
        if (size <=0 || n <=0)
            return;
        if(c[n][size] == c[n-1][size]){
            n = n-1;
            cutting_length(size, n, c, rod);
        } else{
            size = size - n;
            cutting_length(size, n, c, rod);
            printf("%d ", rod[n]);
        }
    }

    int main() {
        FILE *file = fopen("input.txt", "r");
        if(file ==NULL){
            printf("Unable to open file\n");
            return 0;
        }
        int n;
        fscanf(file, "%d", &n);
        int rod[n+1];
        for (int i = 0; i <=n; ++i) {
            if(i==0){
                rod[i] =0;
            } else{
                fscanf(file, "%d", &rod[i]);
            }
        }
        int price[n+1];
        for (int i = 0; i <=n; ++i) {
            if(i==0){
                price[i] = 0;
            } else{
                fscanf(file, "%d", &price[i]);
            }

        }
        int rodSize;
        fscanf(file, "%d", &rodSize);
        fclose(file);

        int  c[n+1][MAX_VALUES];

        for (int i = 0; i <= rodSize; ++i) {
            c[0][i] = 0;
        }

        for (int i = 0; i <=n; ++i) {
            c[i][0] = 0;
        }

        for (int i = 1; i <=n; ++i) {
            for (int j = 1; j <=rodSize; ++j) {

                if(i <= j){
                    c[i][j] = max(c[i-1][j], price[i] + c[i][j-i]);
                } else{
                    c[i][j] = c[i-1][j];
                }
            }

        }
        printf("Maximum profif is: %d\n", c[n][rodSize]);

        printf("Cutting rod length is: ");
        cutting_length(rodSize, n, c, rod);

        return 0;
    }

int max(int i, int j) {
    return (i > j)? i:j;
}

