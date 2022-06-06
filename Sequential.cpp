#include <iostream>
using namespace std;

bool isPrime(int num){
    if(num == 2 || num == 3)
        return true;
	if(num % 2 == 0 || num % 3 == 0){
		return false;
	}

	for(int i = 5; i * i <= num; i += 6 ){
		if(num % i == 0 || num % (i + 2) == 0)
			return false;
	}

	return true;
}

int calculatePoint(int num){
	int total = 0;
	for(int i = 1; i < num; i++){
		if(isPrime(i)){
			total += i;
		}
	}

	return total;
}

int main(){
	int i;
	long total = 0;
	for(i = 1; i <= 50000; i++){
        total += calculatePoint(i);
	}

    cout << total;
}
