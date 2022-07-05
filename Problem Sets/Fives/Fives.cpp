#include <iostream>
using namespace std;

int main(){
    int start, finish, counter = 0;
    cin >> start >> finish;

    for(int i = start; i <= finish; i++){
        int temp = (i < 0) ? -i : i; // absolute value
        bool five = false;
        //checks to see if a 5 is present
        while(temp != 0){
            if(temp % 10 == 5){
                five = true;
                break;
            }
            temp /= 10;
        }
        if(!five) // if not, increment the counter
            counter++;
    }

    cout << counter;
}
