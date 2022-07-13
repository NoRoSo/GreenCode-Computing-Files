#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N, n; cin >> N >> n; //N being number of elements, n being first n-smallest.

    vector<int> arr;
    for(int i = 0; i < N; i++){
        int temp; cin >> temp;
        arr.push_back(temp);
    }


    vector<int> sorted_arr; //I need the n-smallest
    vector<int> final_ray; //this is the vector that will hold the answer
    copy(arr.begin(), arr.end(), back_inserter(sorted_arr));//copy arr to sorted_arr
    sort(sorted_arr.begin(), sorted_arr.end());//sort

    vector<int> search_arr;//Now that I have the n-smallest, I need to make a spliced vector so there are no duplicates.
    copy(sorted_arr.begin(), sorted_arr.begin() + n, back_inserter(search_arr));

    int final_ray_index = 0;
    for(int i = 0; i < N && final_ray_index < n; i++){
        if(count(search_arr.begin(), search_arr.end(), arr[i])){ //if it's one of the n-smallest
            int temp_index = 0;
            bool found = false;
            while(!found){
                if(search_arr[temp_index] == arr[i]){//removing it so it doesn't affect me anymore.
                    search_arr.erase(search_arr.begin() + temp_index);
                    found = true;
                }
                temp_index++;
            }
            final_ray.push_back(arr[i]);
            final_ray_index++;//checking so we only get the n-smallest.
        }
    }
    for(int i = 0; i < final_ray.size(); i++){
        cout << final_ray[i] << " ";
    }

    return 0;
}
