#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int ray[n];
    for(int i = 0; i < n; i++){
        cin >> ray[i];
    }

    int inv_count = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(ray[i] > ray[j])
                inv_count++;
        }
    }

    cout << inv_count;
}
