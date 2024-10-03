#include <stdio.h>
#include <limits.h>
int L[100];
int L_prime[100];
int prev[100];

void printLIS(int i, int pInt[]);

int main() {
    printf("Enter the length of given array: ");
    int n;
    scanf("%d", &n);
    int a[n+1];
    for (int i = 1; i <= n; ++i) {
        scanf(" %d", &a[i]);
    }
    int len=0;
    L[0] = - INT_MAX;
    L_prime[0] = -1;
    prev[0] = -1;
    for (int i = 1; i <= n; ++i) {
        if(L[len] < a[i]){
            L[++len] = a[i];
            L_prime[len] = i;
            prev[i] = L_prime[len-1];
        } else{
            int s=0, h=len;
            while (s < h){
                int mid = (s+h)/2;
                if(L[mid] < a[i]){
                    s = mid+1;
                } else{
                    h = mid;
                }
            }
            L[s] = a[i];
            L_prime[s] = i;
            prev[i] = L_prime[s-1];
        }
    }
//    int lis_length = len;
//    int lis_indices[lis_length];
//    int current_index = L_prime[lis_length];
//    for (int i = lis_length - 1; i >= 0; --i) {
//        lis_indices[i] = current_index;
//        current_index = prev[current_index];
//    }
//    printf("Lenghtn is: %d\n", len);
//    // Printing the longest increasing subsequence
//    printf("Longest Increasing Subsequence: ");
//    for (int i = 0; i < lis_length; ++i) {
//        printf("%d ", a[lis_indices[i]]);
//    }
    printf("Length is: %d\n", len);

    printLIS(L_prime[len], a);
    return 0;
}

void printLIS(int i, int pInt[]) {
    if(i==-1)
        return;
    printLIS(prev[i], pInt);
    printf("%d ", pInt[i]);

}
