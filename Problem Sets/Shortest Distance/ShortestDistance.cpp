#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases; cin >> cases;
    int case_num = 1;
    while(cases--){
        int N; cin >> N;
        int ray[N];

        for(int i = 0; i < N; i++)
            cin >> ray[i];

        unordered_map<int, int> m;
        int smallest = INT_MAX;

        for(int i = 0; i < N; i++){
            if(m.find(ray[i]) == m.end()){
                m[ray[i]] = i; //if it's not in hashmap
            }else{
		// if it is in hashmap
                if(i - m[ray[i]] < smallest) 
                    smallest = i - m[ray[i]];
                m[ray[i]] = i;
            }
        }
        cout << "CASE #" << (case_num++) << ": " << (smallest == INT_MAX? -1: smallest) << endl;
    }

}


