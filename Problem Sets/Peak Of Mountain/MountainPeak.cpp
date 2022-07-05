#include <iostream>

using namespace std;

int main(){
    //getting input
    int height, width; // rows, cols
    cin >> height >> width;

    char mountain[height][width];
    for(int i = 0; i < height; i++){
        cin.getline(mountain[i], width);
    }

    int peak = 1;
    char edgeChar = ' ';

    while(true){
        bool stop = true;
        char curChar = (char)(peak + '0');
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                if(mountain[i][j] == '^'){
                    stop = false;
                    if((i == 0 || (mountain[i - 1][j] == edgeChar))
                                || (i == height - 1 || (mountain[i + 1][j] == edgeChar))
                                || (j == 0 || (mountain[i][j - 1] == edgeChar))
                                || (j == width - 1 || (mountain[i][j + 1] == edgeChar))){
                                mountain[i][j] = curChar;
                                }
                }
            }
        }
        if(stop){
            cout << peak - 1;
            return 0;
        }else{
            peak += 1;
            edgeChar = curChar;
        }
    }
}
