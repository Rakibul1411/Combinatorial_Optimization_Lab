#include <iostream>
#include <fstream>
using namespace std;

void sum_interval(int prev[], int index, int A[]) {
     if(index <= 0) {
         return;
     }
     if(prev[index] > 0) {
         sum_interval(prev,prev[index], A);
     }
    cout<< A[index]<<" ";
}

int main() {
    ifstream file("input.txt");
    if (!file) {
        cerr << "Unable to open the file." << endl;
        return 1;
    }
    int n;
    file >> n;
    int A[n+1];
    A[0] = 0;
    for (int i = 1; i <=n; ++i) {
        file >> A[i];
    }
    file.close();
    int Sum[n+1];
    Sum[0] = 0;
    int prev[n+1];
    prev[0] = 0;
    int maxSum = A[1], index;

    for (int i = 1; i <=n; ++i) {

        Sum[i] = Sum[i-1] + A[i];
        prev[i] = i-1;

        if(A[i] > Sum[i]){
            Sum[i] = A[i];
            prev[i] = 0;
        }

        if(maxSum <= Sum[i]){
            maxSum = Sum[i];
            index = i;
        }
    }

    cout <<"Maximum value is: " << maxSum << endl;

    cout<< "The maximum_sum interval is: ";
    sum_interval(prev, index, A);


    return 0;
}
