#include <bits/stdc++.h>

using namespace std;

int ans = INT_MAX;

//Uncover the area [r, ..., r+k][c, ..., c+k]
void uncover(vector<vector<bool> >& rect, int r, int c, int k){
    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            rect[r+i][c+j] = false;
        }
    }
}

//Cover the area [r, ..., r+k][c, ..., c+k] with a k * k square
void cover(vector<vector<bool> > &rect, int r, int c, int k){
    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            rect[r+i][c+j] = true;
        }
    }
}

// Check if the area [r, ..., r+k][c, ..., c+k] is already covered
bool isAvailable(vector<vector<bool> > &rect, int r, int c, int k){
    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            if(rect[r + i][c+j])
                return false;
        }
    }

    return true;
}

// (r, c) is the starting point for selecting a square
// rect records the status of current rectangle
// cnt is the number of squares we have covered
void dfs(int r, int c, vector<vector<bool> >& rect, int cnt){
    int n = rect.size(), m = rect[0].size();

    //optimization 1: the current cnt >= the current answer
    if(cnt >= ans)
        return;

    //successfully cover the whole rectangle
    if(r >= n){
        ans = cnt;
        return;
    }

    //successfully cover the area [0, ..., n][0, ..., c] => move to next row
    if(c >= m){
        dfs(r + 1, 0, rect, cnt);
        return;
    }

    //if (r, c) is already covered => move to next point (r, c+1)
    if(rect[r][c]){
        dfs(r, c+1, rect, cnt);
        return;
    }

    //Try all the possible size of squares starting from (r, c)
    for(int k = min(n - r, m - c); k >= 1 && isAvailable(rect, r, c, k); k--){
        cover(rect, r, c, k);
        dfs(r, c+1, rect, cnt + 1);
        uncover(rect, r, c, k);
    }
}

int tilingRectangle(int n, int m){
    vector<vector<bool> > v(n, vector<bool>(m, false));
    dfs(0, 0, v, 0);
    return ans;
}


int main(){
    int T; cin >> T;
    for(int i = 1; i <= T; i++){
        int length, width; cin >> length >> width;
        ans = INT_MAX;
        cout << "CASE #" << i << ": " << tilingRectangle(length, width) << endl;
    }
}
