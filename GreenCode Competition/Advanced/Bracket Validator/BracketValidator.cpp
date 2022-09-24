//Stacks
#include <bits/stdc++.h>

using namespace std;

int main(){
    int tests; cin >> tests;
    int caseNum = 1;
    while(tests--){

        stack<char> brackets;
        string s; cin >> s;
        if(s.size() % 2 != 0){
            cout << "CASE #" << (caseNum++) << ": Invalid" << endl;
            continue;
        }
        bool valid = true;
        for(int i = 0; i < s.size() && valid; i++){
            char temp = s[i];
            if(temp == '(' || temp == '{' || temp == '['){
                brackets.push(temp);
            }else{
                if(brackets.empty()){
                    valid = false;
                    break;
                }
                char opener = brackets.top();
                brackets.pop();
                if(temp == ')' && opener != '(')
                    valid = false;
                if(temp == ']' && opener != '[')
                    valid = false;
                if(temp == '}' && opener != '{')
                    valid = false;
            }
        }
        cout << "CASE #" << (caseNum++) << ": ";
        if(brackets.empty() && valid){
            cout << "Valid" << endl;
        }else{
            cout << "Invalid" << endl;
        }
    }
}
