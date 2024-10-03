#include <iostream>
#include <fstream>
char upperString[500];
char lowerString[500];
using namespace std;

void print_LCS(vector<vector<int>>& b, char upperString[], int m, int n) {
     if(m==0 || n==0)
         return;
     if(b[m][n] == '\\'){
         print_LCS(b, upperString, m-1, n-1);
         cout << lowerString[m];
     }
     else if(b[m][n] == '^'){
         print_LCS(b, upperString, m-1, n);
     } else{
         print_LCS(b, upperString, m, n-1);
     }
}

int main() {
    ifstream file("input.txt");
    int m, n; // m= upper array length, n= lower array length
    file >> m;
    file >> n;
    file >> upperString;
    file >> lowerString;
    file.close();
    vector<vector<int>> c(m+1, vector<int>(m+1, 0));
    //int c[m+1][n+1],
    vector<vector<int>> b(m+1, vector<int>(n+1,0));
    for (int i = 1; i <=m; ++i) {
        c[i][0] = 0;
    }
    for (int i = 1; i <=n; ++i) {
        c[0][i] = 0;
    }

    for (int i = 1; i <=m; ++i) {
        for (int j = 1; j <=n; ++j) {
            if(upperString[i] == lowerString[j]){
                c[i][j] = c[i-1][j-1]+1;
                b[i][j] = '\\';
            }
            else if(c[i-1][j] >= c[i][j-1]){
                c[i][j] = c[i-1][j];
                b[i][j] = '^';
            } else{
                c[i][j] = c[i][j-1];
                b[i][j] = '<';
            }
        }
    }

    print_LCS(b, upperString, m, n);
    cout << endl<< "Longest Common Subsequences Length is: " << c[m][n];
    return 0;
}
