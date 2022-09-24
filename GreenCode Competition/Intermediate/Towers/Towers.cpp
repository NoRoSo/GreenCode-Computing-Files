/*
O(N Log N)
For each cube, we run upper bound binary search on the array to find the tower
with the smallest top cube that's strictly larger than the current cube.

If we find a tower, we add the cube to the top. If not, we make a new tower.

The answer will be the size of the array (since that is how many towers we made).
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> cubes; //storing towers in non-decreasing order
    for(int i = 0; i < N; i++){
        int temp; cin >> temp;
        int low = 0, high = (int)cubes.size();
        while(low < high){ //binary search
            int mid = (low + high) / 2;
            if(cubes[mid] > temp)
                high = mid;
            else
                low = mid + 1;
        }
        if(low == cubes.size())
            cubes.push_back(temp); //create new tower
        else
            cubes[low] = temp; //add to tower
    }
    cout << cubes.size();
}
