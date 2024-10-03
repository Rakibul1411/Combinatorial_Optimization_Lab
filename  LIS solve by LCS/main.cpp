#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
int c[100][100], b[100][100];

void print_value(int len1, int len2, int x[]) {
     if(len1 == 0 || len2==0)
         return;
     if(b[len1][len2] =='\\'){
         print_value(len1-1, len2-1, x);
         cout<< x[len1]<<" ";
     } else if(b[len1][len2] == '^'){
         print_value(len1-1, len2, x);
     } else{
         print_value(len1, len2-1, x);
     }
}

int main() {
    ifstream file("input.txt");

    if(!file){
        cerr<<"Unable to open file";
        return 1;
    }

    int len;
    file >> len;
    int x[len+1];
        x[0] = 0;

    for (int i =1; i <=len ; ++i) {
        if(i==0){
            x[i]=i;
        } else
            file >> x[i];
    }
    file.close();

    int y[len+1];

    for (int i = 0; i <=len ; ++i) {
        if(i==0){
            y[i]=i;
        } else{
            y[i] = x[i];
        }
    }

    sort(y+1, y+len+1);

    for (int i = 0; i <=len ; ++i) {
        c[i][0] = 0;
    }

    for (int i = 0; i <=len ; ++i) {
        c[0][i] = 0;
    }
    for (int i = 1; i <=len ; ++i) {
        for (int j = 1; j <=len ; ++j) {
            if(x[i]==y[j]){
                c[i][j] = c[i-1][j-1]+1;
                b[i][j] = '\\';
            }
            else{
                if(c[i-1][j] > c[i][j-1]){
                    c[i][j] = c[i-1][j];
                    b[i][j] = '^';
                } else{
                    c[i][j] = c[i][j-1];
                    b[i][j] = '<';
                }
            }
        }
    }

    cout<< "LIS length is: " << c[len][len]<< endl;
    cout<<"LIS value is: ";
    print_value(len, len, x);

    return 0;
}
