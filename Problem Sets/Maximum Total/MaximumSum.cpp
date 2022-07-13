#include <iostream>

using namespace std;

int main(){
    int N; cin >> N;

    int ray[N];
    for(int i = 0; i < N; i++)
        cin >> ray[i];

    long long maxSum = 0;
    for(int i = 0; i < N; i++){
        long long tempSum = 0;
        for(int x = i; x < N; x++){
            tempSum += ray[x];
            if(tempSum > maxSum)
                maxSum = tempSum;
        }
    }

    cout << maxSum << endl;

}
