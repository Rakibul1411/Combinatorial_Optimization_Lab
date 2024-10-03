#include <iostream>
#include <fstream>
using namespace std;

void cutting_length(int size, int n, int **c, int *rod) {
    if (size ==0 || n ==0)
        return;
    if(c[n][size] == c[n-1][size]){
        --n;
        cutting_length(size, n, c, rod);
    } else{
        size = size - n;
        cutting_length(size, n, c, rod);
        cout<< rod[n] <<" ";
    }
}

int main() {
    ifstream  file("input.txt");
    if(!file){
        cerr<<"Unable to open file"<< endl;
        return 0;
    }
    int n;
    file >> n;
    int *rod =new int[n+1];
    for (int i = 0; i <=n; ++i) {
        if(i==0){
            rod[i] =0;
        } else{
            file >> rod[i];
        }
    }
    int *price = new int[n+1];
    for (int i = 0; i <=n; ++i) {
        if(i==0){
            price[i] = 0;
        } else{
            file >> price[i];
        }

    }
    int rodSize;
    file >> rodSize;
    file.close();

    int  **c = new int* [n+1];
    for (int i = 0; i <=n; ++i) {
        c[i] = new int[rodSize+1];
    }

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
    cout <<"Maximum profif is: "<< c[n][rodSize] <<endl;

    cout<<"Cutting rod length is: ";
    cutting_length(rodSize, n, c, rod);

    return 0;
}
