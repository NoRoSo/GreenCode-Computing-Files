#include <iostream>

using namespace std;

int main(){
    int tests;
    cin >> tests;
    while(tests--){
        int words, longest = 0;
        cin >> words;
        string ray[words];
        string ast = "";
        for(int i = 0; i < words; i++){
            ast += "*";
            cin >> ray[i];
            if(ray[i].size() > longest)
                longest = ray[i].size();
        }
        for(int x = 0; x < longest; x++){
            for(int i = 0; i < words; i++){
                if(ray[i].size() > x){
                    cout << ray[i][x];
                }else{
                    cout << " ";
                }
            }
            cout << endl;
        }
        cout << ast << endl;
    }

    return 0;
}
