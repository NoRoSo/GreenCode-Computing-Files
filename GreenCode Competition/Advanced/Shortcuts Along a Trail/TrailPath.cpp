//BFS, queues
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > graph;
vector<int> moves;//(101, 100);
vector<bool> visit;//(101, false);
queue<int> fifo;

void bfs()
{
    while(!fifo.empty())
    {
        int a = fifo.front();
        fifo.pop();
        for(int i = 0; i < graph[a].size(); i++) //on each row, we're looking for the maximum move each time.
        {
            int b = graph[a][i];
            if(!visit[b])
            {
                visit[b] = true; //so we don't go back.
                moves[b] = min(moves[b], moves[a] + 1); //meaning the smallest number of steps it took to get to that specific spot.
                fifo.push(b);
            }
        }
    }
}

int main()
{
    int t; cin >> t;
    int testNum = 1;
    while(t--)
    {
        //we could have initialized the vectors globally since we already know the size, but since we are running multiple test cases, we want them to be cleaned each time
        graph = vector<vector<int> > (101);
        moves = vector<int> (101, 100); //initializing moves to 100 to set a maximum.
        visit = vector<bool> (101, false);
        //initialize graph assuming no shortcuts
        for(int i = 1; i <= 100; i++)
        {
            for(int j = 1; j <= 6 && i + j <= 100; j++)
            {
                graph[i].push_back(i+j);
            }
        }

        int l;
        cin >> l;
        int u, v;
        //make modifications for uphill shortcuts
        for(int i = 0; i < l; i++)
        {
	    cin >> u >> v;
            int j = u - 6;
            if(j < 1) //as j can be less than 1 for initial values
                j = 1;

            for(; j < u; j++)
            {
                for(int k = 0; k < graph[j].size(); k++)
                {
                    if(graph[j][k] == u)
                    {
                        graph[j][k] = v;
                        break;
                    }
                }
            }
        }


        int s;
        cin >> s;
        //make modifications for downhill shortcuts
        for(int i = 0; i < s; i++)
        {
            cin >> u >> v;
            int j = u - 6;
            if(j < 1) //as j can be less than 1 for initial values
                j = 1;

            for(; j < u; j++)
            {
                for(int k = 0; k < graph[j].size(); k++)
                {
                    if(graph[j][k] == u)
                    {
                        graph[j][k] = v;
                        break;
                    }
                }
            }
        }
//        for(vector<int> v : graph){
//            for(int item : v){
//                cout << item << " ";
//            }
//            cout << endl;
//        }

        //now graph is set, use bfs to find shortest path
        fifo.push(1); //since we use 1 indexing and trail always start from 1
        visit[1] = true;
        moves[1] = 0;
        bfs();
//        cout << endl;
//        for(int item : moves){
//            cout << item << " ";
//        }
//        cout << endl;

        cout << "CASE #" << (testNum++) << ": " << moves[100] << endl;
    }
    return 0;
}
