/*
 * the first number is the number of characters (including spaces)
 * the second line are two numbers, the amount of numbers, and the nth largest that will be used for deciphering
 */

#include <iostream>
using namespace std;

char letters[27];

char getLetter(int num) {
	return letters[num % 27];
}

void sort(int temp[], int numbers){
	bool sorted = false;
	while(!sorted){
		sorted = true;
		for( int i = 0; i < numbers - 1; i++){
			if(temp[i] > temp[i+1]){
				sorted = false;
				int t = temp[i];
				temp[i] = temp[i+1];
				temp[i+1] = t;
			}
		}
	}
}

int main(){
	int index = 0;
	for(char c = 'a'; c <= 'z'; c++)
		letters[index++] = c;
	letters[26] = ' ';

	int size = 0;
	cin >> size;
	char message[size];
	index = 0;
	while(size--){
		int numbers, nth;
		cin >> numbers >> nth;

		int temp[numbers];

		for(int i = 0; i < numbers; i++){
			cin >> temp[i];
		}

		sort(temp, numbers);

		message[index++] = getLetter(temp[nth - 1]);
	}

	int n = sizeof(message) / sizeof(message[0]);
	for( int i = 0; i < n; i++)
		cout << message[i];
}
