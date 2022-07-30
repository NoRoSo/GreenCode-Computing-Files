//multiset (for this answer at least)
#include <bits/stdc++.h>

using namespace std;
int minPatches(vector<int> & a, int n){
    int appends = 0;
    multiset<long> mset;
    for(int i = 0; i < a.size(); i++){
        mset.insert(a[i]);
    }
    long long sm = 1;
    while(sm < n){
        sm = 1;
        for(long x : mset){
            if(sm < x){
                break;
            }else{
                sm += x;
            }
        }
        //Smallest number (sm) that can't be created between 1..N from the elements in the multiset!
        if(sm <= n){
            appends++;
            mset.insert(sm); //append (sm)
        }
        //now we can create sum from 1...number(sm) from the elements in multiset!
    }

    return appends;
}

int main(){
    int T; cin >> T;

    for(int i = 1; i <= T; i++){
        int N, S; cin >> N >> S;
        vector<int> a;
        for(int x=  0; x < N; x++){
            int temp; cin >> temp;
            a.push_back(temp);
        }

        cout << "CASE #" << i << ": " << minPatches(a, S) << endl;
    }
}
