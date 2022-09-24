#include <iostream>

using namespace std;

int main(){
    long long n; cin >> n; //input
    long long sum = 0; //number of digits.
    for(long long i = 1; i <= n; i++){
        long long temp = i, digits = 0;
        while(temp){
            digits++;
            temp /= 10;
        }
        sum += digits;
    }

    cout << sum;
}
