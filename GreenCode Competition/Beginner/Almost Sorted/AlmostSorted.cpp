//stack

#include <bits/stdc++.h>

using namespace std;

void findUnsortedSubarray(vector<int> &nums){
    stack<pair<int, int>> st; //storing value and index

    int mini = INT_MAX, maxi = INT_MIN;

    int n = nums.size();

    for(int i = 0; i < n; i++){
        int t_min = i, t_max = i;
        int up = nums[i];

        while(!st.empty() && nums[i] < st.top().first){ //taking the current number and comparing to see if it's smaller than anything that's come before.
//            cout << st.top().first << " " << st.top().second << endl;
            pair<int, int> a = st.top(); st.pop();
            t_min = a.second;
            mini = min(mini, t_min); //we're taking the smallest number out of place we can find and seeing where it goes.
            maxi = max(maxi, t_max); //we're taking the largest number out of place and seeing where it goes/
            up = max(up, a.first);
        }
//        cout << "up == " << up << " t_max == " << t_max << endl;
        st.push({up, t_max}); //push the max element which represents the whole subarray w/ current index.
//        cout << "mini == " << mini << " maxi == " << maxi << endl << endl;
    }

    if(mini == INT_MAX && maxi == INT_MIN){
        cout << "already sorted" << endl;
    }else{
        cout << "[" << mini << ", " << maxi << "]" << endl;
    }
}

int main(){
    int N; cin >> N;

    vector<int> v;
    for(int i = 0; i < N; i++){
        int temp; cin >> temp;
        v.push_back(temp);
    }

    findUnsortedSubarray(v);
    return 0;
}
