/*
This is the coin problem https://www.hackerrank.com/challenges/coin-change/problem?isFullScreen=true
This solution is O(2^n) on purpose to base it off of worst, but easiest solution (brute force)

This is a dynamic programming problem, and the fastest I could find is O(numbers + sum)
*/
#include <iostream>

using namespace std;

long long count(int numbers[], int size, int sum){
    //solution exists since we subtracted the right amount.
    //so we increment by one.
    if(sum == 0)
        return 1;

    //no solution exists since we subtracted more than needed.
    //no increment.
    if(sum < 0)
        return 0;

    //no numbers exist anymore to satisfy and the sum is greater than 0
    //no increment.
    if(size <= 0 && sum >= 1)
        return 0;

    //sum of solutions is the first call
    //calling next possibility is the second call.
    return count(numbers, size - 1, sum) + count(numbers, size, sum - numbers[size - 1]);
}

int main(){
    int N, sum; cin >> N >> sum;
    int ray[N];

    for(int i = 0; i < N; i++){
        cin >> ray[i];
    }

    cout << count(ray, N, sum);
}
