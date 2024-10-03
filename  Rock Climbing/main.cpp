#include <iostream>
#include <fstream>

using namespace std;
#define Size 100
int c[Size][Size];
int store[Size][Size];


void print_path(int a, int b, int m);

int min_f(int a, int b, int c){
    if(a<=b && a<=c){
        return a;
    }
    else if(b<=a && b<=c){
        return b;
    } else{
        return c;
    }
}
int main() {
    ifstream file("Input.txt");

    if (!file.is_open()) {
        cout << "Error opening file\n";
        return 1;  // indicate an error
    }

    cout << "Enter the row numbers: ";
    int n, m;
    file >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            file >> c[i][j];
        }
    }

    file.close();

    for (int i = 0; i <= n ; ++i) {
                store[i][0] = INT_MAX;
                store[i][m+1] = INT_MAX;
    }
    for (int i = 0; i <= n ; ++i) {
        for (int j = 1; j <= m ; ++j) {
                store[i][j] = 0;
        }
    }

    int minm, a, b;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if(i == 1){
                store [i][j] = c[i-1][j-1];
            } else {
                store[i][j] = c[i-1][j-1] + min_f(store[i - 1][j - 1], store[i - 1][j], store[i - 1][j + 1]);
            }
            if(i==n) {
                minm = store[i][j];
                for (int k = 1; k <= m; ++k) {
                    if (store[i][k] < minm){
                        minm = store[i][k];
                    }
                }
            }
        }
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m+1; ++j) {
              cout<<store[i][j]<<" ";
        }
        cout<<endl;
    }

    for (int i = 0; i <= m; ++i) {
        if(minm == store[n][i]){
            a = n;
            b = i;
        }
    }
    cout<<"PATH IS: ";
    print_path(a, b, m);
    return 0;
}

void print_path(int a, int b, int m) {
    if(a == 0 || b == 0 || b == m+1){
        return;
    }
//    cout<<c[a-1][b-1]<<" ";

    if(store[a-1][b-1] <= store[a-1][b] && store[a-1][b-1] <= store[a-1][b+1]){
        print_path(a-1, b-1, m);
    }
    else if(store[a-1][b] <= store[a-1][b-1] && store[a-1][b] <= store[a-1][b+1]){
        print_path(a-1, b, m);
    }
    else if(store[a-1][b+1] <= store[a-1][b-1] && store[a-1][b+1] <= store[a-1][b]){
        print_path(a-1, b+1, m);
    }
    cout<<c[a-1][b-1]<<" ";
}

