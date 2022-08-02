#include <bits/stdc++.h>

using namespace std;

int mod = 1000000007;

int main(){
    int T; cin >> T;
    for(int cases = 1; cases <= T; cases++){
        int n, d, f;
        cin >> n >> d >> f;
        map<int, int> mp;//day, people infected
        mp[1] = 1;
        long long res = 0;
        //traverse each new member
        for(auto m : mp){
            //traverse each day of member
            for(int i = m.first; i < min(m.first + f, n + 1); i++){
                // if it is nth day so be simple, add all new members counts
                if(i == n){
                    res = (res % mod + m.second % mod) % mod;
                }
                // add all new members with which it spreads disease after delay time
                if(i >= m.first + d){
                    mp[i] = (mp[i] % mod + mp[m.first] % mod) % mod;
                }
            }
        }

        cout << "CASE #" << cases << ": " << res << endl;
    }
}
