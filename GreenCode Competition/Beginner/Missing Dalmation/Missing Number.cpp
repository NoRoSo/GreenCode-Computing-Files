/*
This problem deals with mathematics, but can also be solved using sorting.
O(N) solution and O(1) space, So this is the ideal solution, but typically
somebody starting out won't come to this solution immediately.
*/
#include <iostream>
using namespace std;

int main(){
    long long len;
    long long sum;
    cin >> len;
    sum = (len * (len + 1))/2; // an equation I learned in calculus II. It calculates the sum from 1...n

    for(int i = 0; i < len - 1; i++){
        int temp;
        cin >> temp;
        sum -= temp; // subtracting from the sum
    }

    cout << sum; // left with the missing number

}
