#include <iostream>

using namespace std;

int main(){
    int N; cin >> N;
    int ray[N][N];

    for(int i = 0; i < N; i++){
        for(int x = 0; x < N; x++){
            cin >> ray[i][x];
        }
    }

    int target; cin >> target;
    for(int i = 0; i < N; i++){
        for(int x = 0; x < N; x++){
            if(ray[i][x] == target){
                cout << "Found in row " << (i+1) << " and column " << (x + 1) << endl;
                return 0;
            }
        }
    }

    cout << "not found" << endl;
    return -1;
}
