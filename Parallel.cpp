#include <iostream>
#include <omp.h>
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
    omp_set_num_threads(4);
    long total[] = {0,0,0,0};
	int i;

	#pragma omp parallel for private(i)
	for(i = 1; i <= 50000; i++){
	    int calcPoint = calculatePoint(i);
	    total[omp_get_thread_num()] += calcPoint;

	}

    cout << total[0] + total[1] + total[2] + total[3];
}
