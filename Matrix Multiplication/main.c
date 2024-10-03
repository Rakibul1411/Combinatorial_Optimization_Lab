#include <stdio.h>
#include <limits.h>
int m[20][20];
int s[20][20];

void print_optimal_parenthesis( int i, int j) {
    if(i==j){
        printf("A%d", i);
    }
        else {
        printf("(");
        print_optimal_parenthesis(i, s[i][j]);
        print_optimal_parenthesis(s[i][j] + 1, j);
        printf(")");
    }
}

void calculate_Cost(int arr[], int size) {
    size = size-1;
    for (int i = 1; i <= size; ++i) {
        m[size][size] = 0;
    }
    for (int l = 1; l <= size-1; ++l) {
        for (int i = 1; i <= size-l; ++i) {
            int j = i+l;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j-1; ++k) {
                int cost = m[i][k]+m[k+1][j]+arr[i-1]*arr[k]*arr[j];
                if(cost < m[i][j]){
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    printf("Minimun no. of cost: %d\n", m[1][size]);
    printf("Multiplication form: ");
    print_optimal_parenthesis(1, size);

}

int main() {
    int p[]={10, 5, 1, 10, 2, 10};
    int size = sizeof (p)/sizeof (p[0]);
    calculate_Cost(p, size);
    return 0;
}
