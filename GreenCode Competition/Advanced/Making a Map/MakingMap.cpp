//DFS, flood fill, etc.
#include <bits/stdc++.h>

using namespace std;

void dfs(int i, int j, vector<vector<int> > & vis, vector<vector<char> > & grid){
    if(i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || vis[i][j] != -1 || grid[i][j] == '0')
        return;

    vis[i][j] = 0;
    dfs(i - 1, j, vis, grid);
    dfs(i + 1, j, vis, grid);
    dfs(i, j - 1, vis, grid);
    dfs(i, j + 1, vis, grid);
}

int numIslands(vector<vector<char> > & grid){ //going through and filling up the island with 0's. increments by 1 for that said island.
    int ans = 0, m = grid.size(), n = grid[0].size();
    vector<vector<int> > vis(m, vector<int>(n, -1));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(vis[i][j] == -1 && grid[i][j] == '1'){
                ans++;
                dfs(i, j, vis, grid);
            }
        }
    }
    return ans;
}

int main(){
    int R, C; cin >> R >> C;
    vector<vector<char> > islands;
    for(int i = 0; i < R; i++){
        vector<char> temp;
        for(int x = 0; x < C; x++){
            char charTemp; cin >> charTemp;
            temp.push_back(charTemp);
        }
        islands.push_back(temp);
    }

    cout << numIslands(islands) << endl;
}
