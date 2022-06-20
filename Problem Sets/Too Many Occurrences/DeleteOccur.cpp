#include <iostream>

using namespace std;

int main(){
    int length, n;
    cin >> length >> n;
    int a[length];
    for(int i = 0; i < length; i++)
        cin >> a[i];
    // everything above is getting input ^^

    int size=length; // the size of the new array
    for(int i=0;i<length;i++){
        int count=0;//to check presence of elements
        for(int j=0;j<length;j++)
            if(a[i]==a[j])
                count++;

        if(count > n && a[i]!=-1){
            int check=count;

            for(int k=length-1;k>=0;k--){
                if(check>n){
                    if(a[k]==a[i]){
                        a[k]=-1; // changing each extra occurrence to -1
                        size--; // decrementing the size of new array
                        check--;
                    }
                }
            }
        }
    }
    for(int i=0;i<length;i++) // printing out the solution.
        if(a[i]!=-1)
            cout << a[i] << " ";

}
