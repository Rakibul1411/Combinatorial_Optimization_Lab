#include <stdio.h>

long long int fiboSeries(long long int i, long long int arr[]) {
    if(i<=1) {
        arr[i]=i;
        return i;
    }  else if(arr[i]<0){
        long long int p;
        if(arr[i]==0){
            return p;
        } else {
            p = fiboSeries(i - 1, arr) + fiboSeries(i - 2, arr);
            arr[i]=p;
            return p;
        }
    }
    return arr[i];
}

int main() {
    long long int num;
    printf("Enter the number of elements in the series: ");
    scanf("%lld", &num);
    long long int arr[num+1];
    for (long long int i = 0; i < num; ++i) {
        arr[i]=-1;
    }
    for (long long int i = 0; i < num; ++i) {
        printf("%lld ", fiboSeries(i, arr));
    }
    return 0;
}
