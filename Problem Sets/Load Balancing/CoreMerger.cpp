//min-heap priority queue

#include <bits/stdc++.h>

using namespace std;


int main() {

    int N, K;
    priority_queue<int, vector<int>, greater<int>> A; //It's least to greatest
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        int temp; cin >> temp;
        A.push(temp);
    }
    int count = 0;
    while (A.top() < K) {
        if (A.size() < 2) {
            cout << "-1\n";
            return 0;
        }
        int m1 = A.top();
        A.pop();
        int m2 = A.top();
        A.pop();

        A.push(m1 + 2 * m2);
        count++;
    }
    cout << count << endl;
    return 0;
}
