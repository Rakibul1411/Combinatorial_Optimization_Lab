#include <iostream>
#include <fstream>
using namespace std;
int m[100][100];
int s[100][100];

void print_matrix(int i, int j);

int main() {
    ifstream file("input.txt");
    if(!file){
        cerr<<"Unable to open file";
    }
    int n;
    file >> n;
    int p[n];
    for (int i = 0; i <n; ++i) {
        file >> p[i];
    }
    file.close();

    for (int i = 1; i < n; ++i) {
        m[i][i] = 0;
    }
    for (int l = 1; l <= n-2; ++l) {
        for (int i = 1; i <= n-l-1; ++i) {
            int j = i+l;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j-1; ++k) {
                int cost = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(cost < m[i][j]){
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    cout <<"Minimum cost for Matrix Multiplication: " << m[1][n-1]<<endl;

    cout<<"Matrix Multiplication is the form of : ";
    print_matrix(1, n-1);
    return 0;
}

void print_matrix(int i, int j) {
    if(i==j){
        cout << "A"<<i;
    }
    else{
        cout<<"(";
        print_matrix(i, s[i][j]);
        print_matrix(s[i][j]+1, j); // Using DFS for printing the matrix; Inorder Traversal use;
        cout<<")";

    }

}
