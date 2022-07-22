//gray code
#include <bits/stdc++.h>

using namespace std;

int minimumOperations(int n){
    int output = 0;

    while( n > 0){
        output ^= n; //xor
        n = n >> 1; //binary shift to the right 1
    }

    return output;
}

int main(){
    int cases; cin >> cases;
    for(int i = 1; i <= cases; i++){
        int temp; cin >> temp;
        cout << "CASE #" << i << ": " << minimumOperations(temp) << endl;
    }

    return 0;
}
