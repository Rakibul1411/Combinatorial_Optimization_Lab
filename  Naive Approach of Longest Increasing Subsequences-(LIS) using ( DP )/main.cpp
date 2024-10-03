#include <iostream>
#include <fstream>

void print_LIS(int maxindex, int prev[], int a[]);

using namespace std;
int main() {
    ifstream file("input.txt");
    if(!file){
        cerr<<"Unable to open file"<<endl;
    }
    int n;
    file >> n;
    int a[n+1];
    for (int i = 0; i <=n ; ++i) {
        if(i==0)
            a[i] =0;
        else{
            file >> a[i];
        }
    }
    file.close();
    int len[n+1];
    len[0] = 0;
    int prev[n+1];
    prev[0] = -1;
    int maxlen=0;
    int maxindex=0;
    for (int i = 1; i <=n; ++i) {
        len[i] =0;
        for (int j = 0; j <= i-1; ++j) {
            if (a[j] < a[i] && len[j] + 1 >= len[i]) { // if len[j] +1 > len[i]; the print another subsequences;
                len[i] = len[j] + 1;
                prev[i] = j;
            }
        }
        if (len[i] > maxlen) {
            maxlen = len[i];
            maxindex = i;
        }
    }
    cout<<"max len is:"<< maxlen << " " << maxindex<< endl;

    for (int i = 0; i <=n; ++i) {
        cout<< prev[i]<<" ";
    }
    cout<< endl;
    for (int i = 0; i <=n; ++i) {
        cout<< a[i]<<" ";
    }
    cout<< endl<< "Subsequences is: ";
    print_LIS(maxindex, prev, a);
    return 0;
}

void print_LIS(int maxindex, int prev[], int a[]) {
    if(prev[maxindex] == -1) {
        return;
    }
    print_LIS(prev[maxindex], prev, a);
    cout << a[maxindex] << " ";

}
