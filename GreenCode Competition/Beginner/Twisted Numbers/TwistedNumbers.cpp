#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int switchNumber(int n){
    int newNum = 0;
    int power_ten = 0;
    while(n){
        int temp = 10 - (n % 10);
        if(temp == 10)
            temp = 0;
//        switch(n % 10){
//        case 0:
//            temp = 0; break;
//        case 1:
//            temp = 9; break;
//        case 2:
//            temp = 8; break;
//        case 3:
//            temp = 7; break;
//        case 4:
//            temp = 6; break;
//        case 5:
//            temp = 5; break;
//        case 6:
//            temp = 4; break;
//        case 7:
//            temp = 3; break;
//        case 8:
//            temp = 2; break;
//        case 9:
//            temp = 1; break;
//        }
        newNum += temp * pow(10, power_ten);
        n /= 10;
        power_ten++;
    }
    return newNum;
}

int cmp(int o1, int o2){

    o1 = switchNumber(o1);
    o2 = switchNumber(o2);

    return o1 < o2? 1 : o1 == o2? 0 : 0;
}

int main(){
    int n;
    cin >> n;
    int ray[n];

    for(int i = 0; i < n; i++){
        cin >> ray[i];
    }

    sort(ray, ray + n, cmp);

    for(int i = 0; i < n; i++)
        cout << ray[i] << " ";

}
