#include <iostream>
#include <fstream>
using namespace std;
int price[100];
int weight[100];
bool items[100];
int p [100][100];

void printSelectedItems(int n, int w) {
    if(n==0 || w==0)
        return;
    if(p[n][w] != p[n-1][w]){
        items [n] = true;
        printSelectedItems(n-1, w-weight[n]);
    }
    else {
        items[n] = false;
        printSelectedItems(n - 1, w);
    }
}

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

        for (int w = 0; w <= W; ++w) {

            if (weight[i] > w) {
                p[i][w] = p[i - 1][w];
            } else {
                p[i][w] = max(price[i] + p[i - 1][w - weight[i]], p[i - 1][w]);
            }

        }

    }


    printSelectedItems(n, W);

    cout << "Selected items: ";
    for (int i = 1; i <= n; ++i) {
        if (items[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
    cout << "Maximum profit is: " << p[n][W];

    return 0;
}

