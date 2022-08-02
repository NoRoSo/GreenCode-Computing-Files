#include <bits/stdc++.h>
using namespace std;

int swimInWater(vector<vector<int>> & grid){
    //pq stores the time, and the grid index of each cell.
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; //minheap of a pair<int, pair<int,int>>.
    int n = grid.size(), m = grid[0].size();
    int dirx[4] = {1, -1, 0, 0};
    int diry[4] = {0, 0, -1, 1};
    int val = 0;
    pq.push({grid[0][0],{0,0}}); //we begin at the top left each time.
    grid[0][0] = -1;
    while(!pq.empty())
    {
        int sz = pq.size();
        while(sz--)
        {
            pair<int, pair<int, int>> tp = pq.top();
            int x = tp.second.first, y = tp.second.second;//matrix index
            pq.pop();
            val = max(val, tp.first);//the max amount of minutes we encounter on the path to the end.
            if(x == n-1 && y == m-1)//OOB
                return val;
            for(int i = 0; i < 4; i++)
            {
                int nxtx = x + dirx[i];
                int nxty = y + diry[i];
                if(nxtx < 0 || nxtx >= n || nxty < 0 || nxty >= m)
                    continue;
                if(grid[nxtx][nxty] == -1)
                    continue;
                pq.push({grid[nxtx][nxty],{nxtx, nxty}});
                grid[nxtx][nxty] = -1;
            }
        }
    }
    return val;
}

int main(){
    int T; cin >> T;

    for(int i = 1; i <= T; i++){//input
        int N; cin >> N;
        vector<vector<int>> grid(N, vector<int>(N));
        for(int x = 0; x < N; x++){
            for(int z = 0; z < N; z++)
                cin >> grid[x][z];
        }

        cout << "CASE #" << i << ": " << swimInWater(grid) << endl;
    }
}
