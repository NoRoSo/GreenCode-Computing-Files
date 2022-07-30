#include <bits/stdc++.h>

using namespace std;

int minimumTime(int n, vector<vector<int> > & relations, vector<int> & time){//main idea, it's making a tree and you travel through all the nodes and return the one that took the longest.
    vector<vector<int> > adjList(n);
    vector<int> inDegree(n), cTime(n, 0);

    for(int i = 0; i < relations.size(); i++){ //create adjacency list and in degree count vectors
        adjList[relations[i][0] - 1].push_back(relations[i][1] - 1);
        inDegree[relations[i][1] - 1]++;
    }
    queue<pair<int, int>> q;

    for(int i = 0; i < n; i++){ //get all nodes with in-degree = 0 and store add them to the queue.
        if(!inDegree[i])
            q.push({i, 0});
    }

    while(!q.empty()){
        pair<int, int> node = q.front(); //process node 'node'. node is .first and 't' is .second
        q.pop();

        //Completion time of the current node the time when the processing started 't'
        //(Max time at which prerequisites completed) + the time taken to process it 'time[node]'.
        int completionTime = node.second + time[node.first];
        cTime[node.first] = completionTime; //store the final completion time of the node 'node'.

        for(int &n : adjList[node.first]){
            //update the intermediate completion time of the child node 'n'.
            //this means that node 'n' would start processing at least at 'cTime[n]'.
            cTime[n] = max(cTime[n], completionTime);

            if(!--inDegree[n]) //Add the node with in-degree = 0 to the queue.
                q.push({n, cTime[n]});
        }
    }
    //Return the maximum time it took for a node/course to complete as our result.
    return *max_element(cTime.begin(), cTime.end());
}

int main(){
    int C, R; cin >> C >> R;
    vector<vector<int> > connections;
    for(int i = 0; i < C; i++){
        vector<int> temp(2);
        cin >> temp[0] >> temp[1];
        connections.push_back(temp);
    }

    int m; cin >> m;
    vector<int> time(m);
    for(int i = 0; i < m; i++){
        cin >> time[i];
    }


    cout << minimumTime(R, connections, time) << endl;

}
