#include <iostream>

using namespace std;

int main(){
    int tests; cin >> tests;

    for(int i = 1; i <= tests; i++){
        int counter = 0;
        long n; cin >> n;
        while(n != 1){
            if(n % 2 ==0){
                n /= 2;
            }else{
                if(((n-1) / 2) % 2 == 0 || n - 1 == 2){ //we want to do action that gives us the most amount of even numbers in a row.
                    n--;
                }else{
                    n++;
                }
            }
            counter++;
        }
        cout << "CASE #" << i << ": " << counter << endl;
    }
}
