#include <bits/stdc++.h>
using namespace std;

int check(int evens[], int odds[], int n){
    int o, e; //odd, even
    if(n % 2 ==0){
        o = n / 2;
        e = n / 2;
    }else{
        e = n / 2;
        o = n - e;
    }

    int moves = INT_MAX;
    //choose 1 at odds and 0 at evens
    moves = min(moves, max(o - odds[1], 0) + max(e - evens[0], 0));
    //choose 1 at evens and 0 at odds
    moves = min(moves, max(e - evens[1], 0) + max(o - odds[0], 0));

    return moves;
}

int minFlips(string s){
    int n = s.length();
    s += s;

    int odds[2] = {0,0}, evens[2] = {0, 0};

    int i = 0;
    //this code uses 1-based indexing for finding divisibility
    while(i < n){//counts how many 1's and 0's are in odd/even places
        if((i + 1) % 2 == 0){
            evens[s[i] - '0']++;
        }else{
            odds[s[i] - '0']++;
        }
        i++;
    }
//    cout << "odds == " << odds[0] << " " << odds[1] << endl;
//    cout << "evens == " << evens[0] << " " << evens[1] << endl;

    int ans = INT_MAX;
    ans = min(ans, check(evens, odds, n));
    int j = i;
    i = 0;
    while(j < s.length()){
        //shrink from back and reduce odds
        //since 1 element is removed it will always be odd
        odds[s[i++] - '0']--;
        //after shifting, odds become evens and evens become odds
        swap(evens[0], odds[0]);
        swap(odds[1], evens[1]);
        //add the new added character to appropriate position
        //added characters position depends on the size of window/given string
        if(n % 2 == 0)
            evens[s[j] - '0']++;
        else
            odds[s[j] - '0']++;
        ans = min(ans, check(evens, odds, n));
        j++;
    }

    return ans;
}

int main(){
    int T; cin >> T;
    for(int cases = 1; cases <= T; cases++){
        string s; cin >> s;
        cout << "CASE #" << cases << ": " << minFlips(s) << endl;
    }
}
