#include <bits/stdc++.h>

using namespace std;

int main(){
    int cases; cin >> cases;

    int caseNum = 1;
    while(cases--){
        int friends; cin >> friends;
        //hashmap <integer, ordered_set
        map<int, priority_queue<string, vector<string>, greater<string>>> m;
        int best = -1;
        for(int i = 0; i < friends; i++){
            string name; cin >> name;
            int texts; cin >> texts;

            if(texts > best)
                best = texts;

            m[texts].push(name);
        }
        cout << "CASE #" << (caseNum++) << ": ";
        if(m[best].size() == 1){
            cout << m[best].top() << " is my best friend!" << endl;
        }

        if(m[best].size() == 2){
            string f1 = m[best].top(); m[best].pop();
            string f2 = m[best].top();
            cout << f1 << " and " << f2 << " are my best friends!" << endl;
        }

        if(m[best].size() > 2){
            while(m[best].size() != 1){
                string temp = m[best].top(); m[best].pop();
                cout << temp << ", ";
            }
            cout << "and " << m[best].top() << " are my best friends!" << endl;
        }
    }

    return 0;
}
