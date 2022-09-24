//Segment Tree
#include <bits/stdc++.h>

using namespace std;

int seg[10000005];
void update(int node, int start, int end, int pos){
    if(start > pos || end < pos){
        return;
    }
    if(start == end){
        seg[node] += 1;
        return;
    }

    int mid = (start + end) / 2;
    update(node*2+1, start, mid, pos);
    update(node*2+2, mid + 1, end, pos);
    seg[node] = seg[node*2+1] + seg[node*2+2];
}

int get(int node, int start, int end, int left, int right){
    if(start > right || end < left){
        return 0;
    }
    if(left <= start && end <= right){
        return seg[node];
    }
    int mid = (start + end) / 2;
    return get(node * 2 + 1, start, mid, left, right) + get(node * 2 + 2, mid + 1, end, left, right);
}

int main(){
    int N; cin >> N;
    vector<int> nums;
    vector<long long> contain;
    for(int i = 0; i < N; i++){
        int temp; cin >> temp;
        nums.push_back(temp);
        contain.push_back(temp);//we push back the original val and (val*2).
        contain.push_back(1LL * 2 * temp);
    }
    sort(contain.begin(), contain.end());

    map<long long, long long> pos; //storing the last index of each value.

    for(int i = 0; i < contain.size(); i++)
        pos[contain[i]] = i;

    int res = 0;

    for(int i = nums.size() - 1; i >= 0; i--){
        res += get(0,0, N * 2, 0, pos[nums[i]] - 1);
        update(0, 0, N * 2, pos[1LL * nums[i] * 2]);
    }

    cout << res << endl;
}
