/*
Deals with encryption plus string manipulation
*/

#include <iostream>

using namespace std;

void encrypt(string s, int N){
    char encrypted[s.size()]; // the final encrypted string
    for(int i = 0; i < s.size(); i++)
        encrypted[i] = '.'; // filling the array with '.'

    int index = 0;
    int initial = 0;
    for(int i = 0; i  < s.size(); i++){
        encrypted[index] = s[i]; // the current char
        if(index + N >= s.size()){
            if(initial + 1 >= s.size()){ // OOB or complete with the word
                break;
            }
            if(encrypted[initial + 1] == '.'){ // if it hasn't been changed yet.
                initial++;
                index = initial;
                continue;
            }else{
                break;
            }
        }
        index = (index + N) % s.size(); //going to the next letter.
    }

    for(int i = 0; i < s.size(); i++) //printing solution
        cout << encrypted[i];
}

int main(){
    int N, W; //n, words
    cin >> N >> W;

    string s;
    for(int i = 0; i < W; i++){
        string temp;
        cin >> temp;
        s += temp;
    }
    encrypt(s, N);
}
