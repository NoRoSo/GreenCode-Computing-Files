//https://www.codewars.com/kata/reviews/5802ca0c8311e027bd0000a3/groups/62c390400562dc0001f630e2
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int N; cin >> N;
    while(N--){
    int n; cin >> n;

    int arrayLength = 0;
    long nn = n;
    while(nn > 0){
        nn /= 10;
        arrayLength++;
    }

    long number[arrayLength];
    for(int i = 0; i < arrayLength; i++){
        number[i] = ((n % ((long) pow(10, (i + 1)))) / ((long) pow(10, i)));
    }

    int leftIndex = 0, rightIndex = 0, flag = 0;
    for(int left = 1; left < arrayLength; left++){
        for(int right = left - 1; right >= 0; right--){
            if(number[right] < number[left]){
                leftIndex = left;
                rightIndex = right;
                flag = 1;
            }
        }
        if(flag == 1)
            break;
    }
    if(flag == 0){
        cout << -1;
        return 0;
    }

    for(int right = leftIndex - 1; right >= 0; right--){
        if((number[right] > number[rightIndex]) && (number[right] < number[leftIndex]))
            rightIndex = right;
    }
    long temp = number[rightIndex];
    for(int ind = rightIndex; ind < leftIndex; ind++)
        number[ind] = number[ind + 1];

    number[leftIndex] = temp;

    for(int i = leftIndex - 1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(number[j] > number[j+1]){
                temp = number[j];
                number[j] = number[j+1];
                number[j+1] = temp;
            }
        }
    }
    long output = 0;
    for(int ind = 0; ind < arrayLength; ind++){
        output += number[ind] * ((long) pow(10, ind));
    }
    if(number[arrayLength - 1] == 0){
        cout << -1;
        return 0;
    }
    cout << output;
    }
    return 0;
}
