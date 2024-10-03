#include <iostream>
#include <fstream>
char upperString[500];
char lowerString[500];
using namespace std;
int main() {
    ifstream file("input.txt");
    int m, n; // m= upper array length, n= lower array length
    file >> m;
    file >> n;
    file >> upperString;
    file >> lowerString;
    file.close();
    int c[m+1][n+1], b[m+1][n+1];
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

    cout << "Longest Common Subsequences Length is: " << c[m][n];
    return 0;
}
