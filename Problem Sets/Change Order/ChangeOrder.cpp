//ad hoc, I used an array
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K, Q; cin >> N >> K >> Q;
    int ray[N];
    for(int i = 0; i < N; i++){
        cin >> ray[i];
    }

    for(int i = 1; i <= Q; i++){
        int query; cin >> query;
        cout << "Query #" << i << ": ";
        cout << (ray[ (((query - K) % N) + N) % N]) << endl;
    }
}
