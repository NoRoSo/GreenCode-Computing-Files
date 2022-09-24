/*
We do a custom sort with decreasing attack and increasing defence (when attack is same).

Consider this example: [8,10], [9,8], [7,3], [9,7], [1,5], [3,10]
The sorted array we get is: [9,7], [9,8], [8,10], [7,3], [3,10], [1,5]

    Here, we already have the array in a sorted manner with decreasing attack and increasing defence (when attack is same).
If we ever get a defence lesser than the max we have seen by far, we already know that the attack is less for the current pair, so we get an answer.
In cases where attack at ith position is same as that of i-1th position, the defence is in increasing order, hence, we never get an answer in that case.
*/

#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int>  a, vector<int>  b){
    if(a[0] == b[0]){
        return a[1] < b[1];
    }

    return a[0] > b[0];
}

int main(){
    int S; cin >> S;

    vector<vector<int>> soldiers;

    while(S--){
        vector<int> temp(2);
        cin >> temp[0] >> temp[1];
        soldiers.push_back(temp);
    }

    sort(soldiers.begin(), soldiers.end(), cmp);

    int maxd = 0;
    int ans = 0;

    for(int i = 0; i < soldiers.size(); i++){
        if(soldiers[i][1] < maxd){
            ans++;
        }else{
            maxd = soldiers[i][1];
        }
    }

    cout << ans << endl;
}
