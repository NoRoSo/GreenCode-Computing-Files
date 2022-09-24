#include <bits/stdc++.h>
using namespace std;

int main(){
    int row, col, secs; cin >> row >> col >> secs;

    int seconds[row][col];
    char map[row][col];
    for(int i = 0; i < row; i++){
        for(int x = 0; x < col; x++){
            cin >> map[i][x];
            if(map[i][x] == '0')
                seconds[i][x] = 1;
            else
                seconds[i][x] = 0;
        }
    }

    for(int second = 0; second < secs - 1; second++){
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                if(map[r][c] == '.'){
                    map[r][c] = '0';
                    seconds[r][c] = 1;
                }else{
                    seconds[r][c]++;
                    if(seconds[r][c] >= 3){
                        if(r - 1 >= 0)
                            map[r - 1][c] = '*';
                        if(r + 1 < row)
                            map[r + 1][c] = '*';
                        if(c - 1 >= 0)
                            map[r][c - 1] = '*';
                        if(c + 1 < col)
                            map[r][c + 1] = '*';
                        seconds[r][c] = 0;
                        map[r][c] = '*';
                    }
                }
            }
        }
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                if(map[r][c] == '*')
                    map[r][c] = '.';
            }
        }
    }

    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            cout << map[r][c] << " ";
        }
        cout << endl;
    }

    return 0;
}
