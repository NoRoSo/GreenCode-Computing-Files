//greedy & arrays
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, R; cin >> N >> R;
    vector<bool> v(N + 2 * R); // this is so we don't go out of bounds


    for(int i = 0; i < N; i++){//input
        int curr; cin >> curr;
        v[R + i] = curr;
    }

    int minimum = 0;

    for(int i = 0; i < N;){ //loop to iterate through the list.

        int j = i + R - 1; //going to the next '1'.
        for(; j + R > i; --j){
            if(v[j + R]){
                break;
            }
        }

        if(j + R == i){ //if we haven't visited all neighborhoods and we ran out of '1's to visit.
            cout << "-1";
            return 0;
        }
        ++minimum;
        i = j + R; //the next index is at the next furthest '1'
    }

    cout << minimum << endl;
    return 0;
}
