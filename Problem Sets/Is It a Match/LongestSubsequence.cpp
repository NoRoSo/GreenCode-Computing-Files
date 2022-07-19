#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void LCS(const vector<int> &A, const vector<int> &B) { //Longest Common Subsequence
    int n = A.size(), m = B.size();
    vector<int> lens(m+1,0); // + 1 because of line 22
    vector<vector<int>> prev(n+1,vector<int>(m+1,0)); // +1 because of line 24 & 27

    int topleft;
    for(int i = 1; i <= n; i++) {
        topleft = 0;
        for(int j = 1; j <= m; j++) {
            int len;
            if(A[i-1] == B[j-1]) { // a direct match
                len = topleft+1;
                prev[i][j] = 1; // topleft
            } else {
                if(lens[j] > lens[j-1]) { //if a previous one matched
                    len = lens[j];
                    prev[i][j] = 2; // top
                } else {
                    len = lens[j-1];
                    prev[i][j] = 3; // left
                }
            }
            topleft = lens[j];
            lens[j] = len;
        }
    }
//    for(vector<int> v : prev){
//        for(int item : v){
//            cout << item << " ";
//        }
//        cout << endl;
//    }
    // print LCS
    int i = n, j = m, idx = 0;
    vector<int> lcs(lens[m],0);
    while(prev[i][j] != 0) {
        if(prev[i][j] == 1) {
            lcs[idx++] = A[i-1];
            i--;
            j--;
        } else if(prev[i][j] == 2) {
            i--;
        } else {
            j--;
        }
    }

    cout << lcs.size() << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n), B(m);
    for(int i = 0 ; i < n; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> B[i];
    }//everything above was getting input.
    LCS(A,B);
    return 0;
}
