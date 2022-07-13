#include <iostream>

using namespace std;

int main(){
    int cases, counter = 1; cin >> cases;
    while(cases--){
        cout << "CASE #" << (counter++) << " ";
        bool checked = false;
        int N; cin >> N;
        int ray[N];
        for(int i = 0; i < N; i++){
            cin >> ray[i];
        }

        int left = 0;
        int right = N - 1;

        //check for out of place index
        while(!checked && left < right && ray[left] <= ray[left+1]){
            left++;
        }

        //if left == right, then that means there was no out of place.
        if(!checked && left == right){
            cout << "yes" << endl;
            checked = true;
        }

        //check for out of place index from the right
        while(!checked && right > left && ray[right] >= ray[right - 1]){
            right--;
        }

        //if swapping or reversing would NOT sort the array.
        if(!checked && ((left > 0 && ray[right] < ray[left - 1]) || (right < N-1 && ray[left] > ray[right + 1]))){
            cout << "no" << endl;
            checked = true;
        }

        int m = 0;
        for(m = left + 1; !checked && m < right && ray[m] >= ray[m + 1]; m++){}//nothing's done, but we're seeing if it's a swap or a reversal.
        if(!checked && m == right){
            cout << "yes " << ((right - left < 2) ? "swap " : "reverse ") << (left + 1) << " " << (right + 1) << endl;
            checked = true;
        }

        //if we're NOT dealing with a swap
        if(!checked && (m - left > 1 || ray[left] < ray[right - 1] || ray[right] > ray[left + 1])){
            cout << "no" << endl;
            checked = true;
        }

        //if we're ARE dealing with a swap
        for(int i = right - 1; !checked && m < i && ray[m] <= ray[m + 1]; m++){}

        if(!checked && right - m > 1){
            cout << "no" << endl;
        }else{
            if(!checked)
                cout << "yes " << (left + 1) << " " << (right + 1) << endl;
        }
    }
}
