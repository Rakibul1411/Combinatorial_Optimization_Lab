#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream file ("input.txt");
    int n, m;
    file>>n >> m;
    int c[n];
    for (int i = 0; i < n; ++i) {
        file >>c[i];
    }
    int friends[m][2];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 2; ++j) {
            file>> friends[i][j];
        }
    }
    file.close();

    cout<<n <<" "<<m<<endl;
    for (int i = 0; i < n; ++i) {
        cout<<c[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout<< friends[i][j]<<" ";
        }
        cout<<endl;
    }
//    int sum=0;
//    if(m==0){
//        cout<<"Output is: ";
//        for (int i = 0; i < n; ++i) {
//            sum +=c[i];
//        }
//        cout<< sum<< endl;
//    }

    return 0;
}
