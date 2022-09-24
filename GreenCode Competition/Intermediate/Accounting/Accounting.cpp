//Binary Indexed Tree AKA Fenwick Tree: One of the quickest methods to update a given range of numbers.
#include <bits/stdc++.h>

using namespace std;

class BIT{
private:
    int n;
    vector<int> arr;
    int getNext(int idx){
        return idx + (idx & (-idx));//binary representation equation.
    }
    int getParent(int idx){
        return idx & (idx - 1);//going back one index.
    }
public:
    BIT(int _n): n(_n), arr(_n + 1){
        arr[0] = 0;
        for(int idx = 0; idx < n; ++idx){
            addValue(idx, 1);
        }
    }

    void addValue(int idx, int val){//taking that index and adding previous numbers
        ++idx;
        while(idx < arr.size()){
            arr[idx] += val;
            idx = getNext(idx);
        }
    }

    int getSum(int idx){
        ++idx;
        int sum = 0;
        while(idx > 0){
            sum += arr[idx];
            idx = getParent(idx);
        }
        return sum;
    }
};

int main(){
    int N; cin >> N;
    vector<int> sum(N + 1, 0);
    for(int i = 0; i < N; i++){//input
        int temp; cin >> temp;
        sum[i + 1] = sum[i] + temp;
    }
    int lower, upper; cin >> lower >> upper;

    //begins...
    vector<long long> A(sum.begin(), sum.end());
    sort(A.begin(), A.end());
    BIT tree(A.size());
    int count = 0;
    for(const auto &x : sum){
        int idx = lower_bound(A.begin(), A.end(), x) - A.begin();//lower_bound: Returns an iterator pointing to the first element in the range [first,last) which does not compare less than val.
        int lowerIdx = lower_bound(A.begin(), A.end(), x + lower) - A.begin();
        int upperIdx = upper_bound(A.begin(), A.end(), x + upper) - A.begin() - 1;//upper_bound: Returns an iterator pointing to the first element in the range [first,last) which compares greater than val.

        tree.addValue(idx, -1);
        count += tree.getSum(upperIdx) - tree.getSum(lowerIdx - 1);
    }

    cout << count << endl;
}
