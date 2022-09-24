/*
This code is based off of conways game of life.
This code goes through and creates the next generation in the game.

This is cellular automata, generations, and matrix manipulation.
*/
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    int size;
    cin >> size;
    int mat[size][size];
    int next_gen[size][size];
    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
            cin >> mat[row][col];
        }
    }// everything above is getting the input.
    //solution...
    int pose[16] = {1,1,-1,-1,1,-1,-1,1,1,0,0,1,-1,0,0,-1};
    for(int r = 0; r < size; r++){
        for(int c = 0; c < size; c++){
            int k = 0, a = 0;
            while(k <= 14){
                if( (mat[r + pose[k]][c + pose[k+1]] == 1) &&
                   (r + pose[k] >= 0) && (c + pose[k] >= 0) && (r + pose[k] < size) &&
                   (pose[k+1] + c < size)){
                    a++;
                   }
                k+=2;
            }
            next_gen[r][c] = (a==3)||(a==2 && mat[r][c]) ? 1 : 0;
        }
    }

    //printing solution
    for(int i = 0; i < size; i++){
        for(int x = 0; x < size; x++){
            cout << next_gen[i][x] << " ";
        }
        cout << endl;
    }
}
