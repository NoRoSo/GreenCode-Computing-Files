#include <iostream>

using namespace std;

int main(){
	int cases, len;
	cin >> cases;
	while(cases--){
		cin >> len;
		string s;
		cin >> s;

		for(int guess = 1; guess <= len; guess++){
			bool good = true;

			for(int i = 0; i + guess <= len; i++){
				for(int j = 0; j < i; j++){
					if(s.substr(i, guess) == s.substr(j, guess))
						good = false;
				}
			}
			if(good){
				cout << guess;
				break;
			}
		}
	}

}
