//sliding door algorithm
//hashmap & set
#include <bits/stdc++.h>

using namespace std;

int distinctEchoSubstrings(string text){
    int n = text.size();
    int max_sliding;
    if(n % 2 == 0){//indexing
        max_sliding = n;
    }else{
        max_sliding = n - 1;
    }

    char max_c = text[0], min_c = text[0];//finding the first and last char in alphabetical order
    for(int i = 1; i < n; i++){
        max_c = max(max_c, text[i]);
        min_c = min(min_c, text[i]);
    }
    if(max_c == min_c){ //meaning it's a string of repeating characters
        return max_sliding / 2;
    }

    unordered_set<string> records;
    for(int sliding = max_sliding; sliding >= 2; sliding = sliding - 2){
        int half_sliding = sliding / 2;
        for(int start = 0; start <= n - sliding; start++){
            int back = start + sliding - 1;
            int middle = start + half_sliding - 1;
            //[start, back], whether the substring is echo
            bool is_echo = true;
            for(int i = 0; i < half_sliding; i++){
                if(text[start + i] != text[middle + 1 + i]){//if it echoes
                    is_echo = false;
                    break;
                }
            }
            if(is_echo){
                string sub = text.substr(start, half_sliding);
                if(records.count(sub) == 0){
                    records.insert(sub);
                }
            }
        }
    }
    return records.size();
}

int main(){
    int cases; cin >> cases;

    for(int i = 1; i <= cases; i++){//input
        string word; cin >> word;
        cout << "CASE #" << i << ": " << distinctEchoSubstrings(word) << endl;
    }
}
