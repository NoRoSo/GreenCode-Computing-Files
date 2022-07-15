//deals with stacks
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1300; //size of the prime number array
const int M = 110000; //the first 1200 primes are underneath this integer as well as an arbitrary number
int ans[M], stk[M], tmpstk[M],prim[N];
int atop, top, ttop, n,q, num;

void init(){ //finding the first 1200 prime numbers
    num = 0;
    for(int i = 2; i < M; ++ i){
        bool isfind = false;
        for(int j = 2; j <= sqrt(i); ++ j){
            if(i%j==0){
                isfind = true;
                break;
            }
        }
        if(!isfind){
            prim[num ++] = i;
        }
        if(num >= 1200)
            return ;
    }
}

int main() {
    cin >> n >> q;
    init();
    atop = top = 0; //atop is "final stack" index and top is general index.
    for(int i = 0; i < n; ++ i){ //getting the stack of plates
        cin >> stk[top++];
    }

    //for number of iterations
    for(int i = 0; i < q; ++ i){
        ttop = 0; //index of stack A
        while(top){
            int v = stk[top - 1];
            --top;
            if(v%prim[i] == 0){ // putting them into stack A and B
                ans[atop ++] = v; //Stack B or "final stack"
            }else{
                tmpstk[ttop ++] = v; //Stack A
            }
        }

        while(atop){
            printf("%d\n",ans[atop - 1]); //prints out current values in B/"final stack". This also deals with the reversal.
            --atop;
        }
        for(int j = 0; j < ttop; ++ j){ //assigning stack A to stk.
            stk[j] = tmpstk[j];
        }
        top = ttop;
        if(!top)//if stack A is empty
            break;
    }
    while(top){//printing remaining from bottom to top.
        printf("%d\n",stk[top - 1]);
        -- top;
    }
    return 0;
}
