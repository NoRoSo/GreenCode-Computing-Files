#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int o1, int o2){
    return o2 < o1;
}

int main() {
    int products, customers;
    cin >> products >> customers;

    vector<int> arr;
    for(int i = 0; i < products; i++){
        int temp; cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end(), compare); //sorting in descending order using a custom comparator.

    long long cost = 0;
    for (int i = 0; i < products; i++) {
        //inside the parenthesis, you divide 'i' by the number of customers before adding 1
        //this ensures that each customer gets an expensive product at the lowest price, and a cheap product at the higher costs.
        cost += (1 + i / customers) * arr[i];
    }
    cout << cost;

}
