#include <bits/stdc++.h>

using namespace std;

int main(){
    int V; cin >> V;
    unordered_map<string, int> m;
    for(int i = 0; i < V; i++){
        string temp; cin >> temp;
        m[temp]++;
    }

    int Q; cin >> Q;
    for(int i = 1; i <= Q; i++){
        cout << "Query #" << i << ": ";
        string temp; cin >> temp;
        if(m[temp] == 0){
            cout << "0" << endl;
        }else{
            cout << m[temp] << endl;
        }
    }
}
