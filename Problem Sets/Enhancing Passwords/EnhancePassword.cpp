#include <bits/stdc++.h>

using namespace std;

int passwordChecker(string s){
    int n = s.length(), ans = 0;
    int same[n]; memset(same, 0, sizeof(same));
    bool dig = 1, sml = 1, cap = 1;

    for(int i = 0; i < n;){ //seeing what we're missing.
        if(s[i] >= 'a' && s[i] <= 'z')
            sml = 0;
        if(s[i] >= 'A' && s[i] <= 'Z')
            cap = 0;
        if(s[i] >= '0' && s[i] <= '9')
            dig = 0;

        int j = i;
        while(i < n && s[i] == s[j])//seeing if anything repeats.
            same[j]++, i++;
    }
    for(int item : same)
        cout << item << endl;

    int miss = dig + sml + cap;
    if(n < 6){ //if it's too short then we see how many characters we need to add PLUS anything missing.
        ans = (miss + max(0, 6-(n+miss)));
    }else{
        int over = max(0, n - 20), left = 0;
        ans += over; //deduct how many we went over by.

        for(int i = 1; i < 3; i++){
            for(int j = 0; j < n && over > 0; j++){
                if(same[j] < 3 || same[j] % 3 != (i - 1)) //no 3-peats.
                    continue;
                same[j] -= min(over, i);
                over -= i; //how many more we need to remove.
            }
        }

        for(int i = 0; i < n; i++){
            if(same[i] >= 3 && over > 0){ //still any repeats and if we need to remove anymore.
                int need = same[i] - 1;
                same[i] -= over;
                over -= need;
            }
            if(same[i] >= 3)
                left += same[i] / 3;
        }
        ans += max(miss, left); //how many more we had to remove or change.
    }
    return ans;
}

int main(){
    int cases; cin >> cases;
    int caseNum = 1;
    while(cases--){
        string password; cin >> password;
        cout << "CASE #" << (caseNum++) << ": " << passwordChecker(password) << endl;
    }

    return 0;
}
