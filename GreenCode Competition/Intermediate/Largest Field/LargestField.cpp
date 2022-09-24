#include <bits/stdc++.h>

using namespace std;

vector<int> nextSmaller(vector<int> & arr, int n){ //creates a vector that stores the indices of the next smallest number.
    vector<int> ans(n);
    stack<int> s;

    s.push(-1);

    for(int i = n - 1; i >= 0; i--){
        int cur = arr[i];
        while(s.top() != -1 && arr[s.top()] >= cur){
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

vector<int> prevSmaller(vector<int> & arr, int n){ //creates a vector that stores the indices of the previous smallest number.
    vector<int> ans(n);
    stack<int> s;

    s.push(-1);

    for(int i = 0; i < n; i++){
        int cur = arr[i];
        while(s.top() != -1 && arr[s.top()] >= cur){
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> & heights){
    int n = heights.size();

    vector<int> next(n);
    next = nextSmaller(heights, n);

    vector<int> prev(n);
    prev = prevSmaller(heights, n);

//    cout << "next == ";
//    for(int item : next){
//        cout << item << " ";
//    }
//    cout << endl << "prev == ";
//    for(int item : prev){
//        cout << item << " ";
//    }
//    cout << endl;

    int area = INT_MIN;
    for(int i = 0; i < n; i++){ //this loop and checks for the longest range that all fit under a certain number, then gets that area.
        int l = heights[i];
        if(next[i] == -1){
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}

int main(){
    int T; cin >> T;

    for(int cases = 1; cases <= T; cases++){//input
        int N; cin >> N;
        vector<int> heights;
        for(int i = 0; i < N; i++){
            int temp; cin >> temp;
            heights.push_back(temp);
        }

        cout << "CASES #" << cases << ": " << largestRectangleArea(heights) << endl;
    }
}
