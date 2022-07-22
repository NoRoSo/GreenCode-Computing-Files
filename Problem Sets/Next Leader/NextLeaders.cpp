#include <bits/stdc++.h>

using namespace std;

int main(){
    int N; cin >> N;
    vector<int> v;

    for(int i = 0; i < N; i++){
        int temp; cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    int largest = -1;
    for(int i = 1; i < N; i++){
        int difference = v[i] - v[i-1];
        if(difference > largest)
            largest = difference;
    }

    cout << largest << endl;

    return 0;
}
