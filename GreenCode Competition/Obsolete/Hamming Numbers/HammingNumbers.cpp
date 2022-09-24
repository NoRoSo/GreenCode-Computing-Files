#include <iostream>

using namespace std;

int maxDivide(long long a, long long b){ //taking all factors of 2, 3, and 5 out.
    while(a % b == 0){
        a /= b;
    }
    return a;
}

bool isHam(long long num){ //seeing if it's a multiple of 2, 3, and 5 and nothing else.
    num = maxDivide(num, 2);
    num = maxDivide(num, 3);
    num = maxDivide(num, 5);

    return num == 1;
}

int main()
{
    int n = 1200; // this is the nth hamming number you wish to find.
    long long i = 1;
    int count = 1;
    while(n > count){
        i++;//counting which number we're on.
        if(isHam(i))
            count++; //counting how many hamming numbers we have passed.
    }
    cout << i;
}
