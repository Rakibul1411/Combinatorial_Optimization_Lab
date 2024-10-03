#include <iostream>
#include <fstream>
using namespace std;
int price[100];
int weight[100];
int main() {
    ifstream file("input.txt");

    if( !file ){
        cerr << "Error opening input file." << endl;
        return 1;
    }

    int n, W;

    file >> n;
    file >> W;

    for (int i = 1; i <=n; ++i) {
        file >> price[i];
    }

    for (int i = 1; i <=n; ++i) {
         file >> weight[i];
    }
    file.close();

    int p[n+1][W+1];

    for (int i = 0; i <= n; ++i) {
        p[i][0] = 0;
    }

    for (int w = 0; w <= W; ++w) {
        p[0][w] = 0;
    }

    for (int i = 1; i <= n; ++i) {

        for (int w = 1; w <= W; ++w) {

            if(weight[i] > w){
                p[i][w] = p[i-1][w];
            }

            else{
                p[i][w] = max(price[i]+p[i-1][w-weight[i]], p[i-1][w]);
            }

        }

    }
//    int item[n], k=0, l,j=W;
//    for (int i = n; i >=0; --i) {
//        while(j >=0) {
//            if(p[i][j] != p[i-1][j]){
//                item[k] = i;
//                ++k;
//                int a = p[i][j] - price[i];
//                for ( l = 0; l <=W; ++l) {
//                    if(a == p[i-1][l]){
//                        j = l;
//                        --i;
//                        break;
//                    }
//                }
//            } else{
//                --i;
//                j = l;
//            }
//        }
//    }
//    for(int i=0; i< k; ++k){
//        cout << item[i];
//    }
//    cout<< endl;

    int items[n];
    int k = 0, j = W;

    for (int i = n; i >= 1; --i) {
        if (p[i][j] != p[i - 1][j]) {
            items[k] = i;
            ++k;
            j = j - weight[i];
        }
    }

    cout << "Selected items: ";
    for (int i = k - 1; i >= 0; --i) {
        cout << items[i] << " ";
    }
    cout << endl;
    cout << "Maximum profit is: " << p[n][W];

    return 0;
}
