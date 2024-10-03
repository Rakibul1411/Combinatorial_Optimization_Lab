#include <iostream>
using namespace std;
struct knapsack{
    int item;
    double weight;
    int benefit;
    double value;
    int choice = 1;
}knapsack_size[100];

int no_items, W;
void readInput() {
    cin >> no_items;
    for (int i = 1; i <= no_items ; ++i) {
        cin >> knapsack_size[i].item >> knapsack_size[i].weight >> knapsack_size[i].benefit;
        knapsack_size[i].choice = 1;
    }
    for (int i = 1; i <= no_items; ++i) {
        cout << knapsack_size[i].item <<" "<< knapsack_size[i].weight<<" "<< knapsack_size[i].benefit<<" ";
        cout << knapsack_size[i].choice<< endl;
    }
    for (int i = 1; i <= no_items; ++i) {
        knapsack_size[i].value= (knapsack_size[i].benefit/knapsack_size[i].weight);
    }
    for (int i = 1; i <= no_items; ++i) {
       cout<< knapsack_size[i].value<<" ";
    }
    cin >> W;
}

bool compare(struct knapsack weight1, struct knapsack weigth2){
    return weight1.value > weigth2.value;
}
int main() {
    freopen("input.txt", "r", stdin);
    readInput();

    sort(knapsack_size+1, knapsack_size + no_items+1, compare);
    cout<<endl;
    for (int i = 1; i <= no_items; ++i) {
        cout<< knapsack_size[i].value<<" ";
    }
    int max_profit=0, current_weight=W;
    for (int w = 1;  w<= no_items; ++w) {
      if(knapsack_size[w].weight > current_weight && current_weight !=0){
          knapsack_size[w].choice = 0;
          max_profit += knapsack_size[w].value*current_weight;
          current_weight = 0;
      }
      else if(knapsack_size[w].weight <= current_weight && current_weight !=0){
          knapsack_size[w].choice = 0;
          max_profit += knapsack_size[w].weight*knapsack_size[w].value;
          current_weight -=knapsack_size[w].weight;
      } else if(current_weight ==0){
          break;
      }
    }
    cout<< endl<< "Maximum profit is: "<< max_profit<< endl;

    for (int i = 1; i <=no_items ; ++i) {
        if( ! knapsack_size[i].choice ){
            cout<<knapsack_size[i].item<<" ";
        }
    }
    return 0;
}
