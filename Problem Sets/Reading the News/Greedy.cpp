#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    //getting input
    int N, minutes;
    cin >> N >> minutes;
    int ray[N];
    for(int i = 0; i < N; i++){
        cin >> ray[i];
    }

    //sorting the array
    int len = sizeof(ray) / sizeof(ray[0]);
    sort(ray, ray+len);

    //greedy algorithm
    int algs = 0;
    int index = 0;
    while(minutes >= ray[index] && index < N){
        algs++;
        minutes -= ray[index++];
    }
    //printing solution
    cout << algs;
}
