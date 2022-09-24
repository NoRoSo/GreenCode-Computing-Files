/*
This is an undirected weighted tree. we want to define F(v, w) to be the minimum weight over all edges on the path from v to w.
To do this, we must find how many vertices exist where F(v, w) >= k.

We do a DFS from v. We don't want to traverse an edge with edge weight less than k, so we ignore those. We can then count how many other vertices we have visited.
*/

#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> g[5001];
vector<bool> visited(5001);
int k, v, sol;

void dfs (int v) {
	visited[v] = true;
	for (int i = 0; i < g[v].size(); i++) { //checks all surrounding books
		if (visited[g[v][i].first]) continue; //if we've already gone to this node.
		if (g[v][i].second >= k) {//to see if the weight is greater than or equal to the minimum
			sol++; //incrementing the number of recommended books by one.
			dfs(g[v][i].first); //traveling to the next book.
		}
	}
}

int main () {

	int n, q; //how many connections there are, and how many questions.
	cin >> n >> q;

	for (int i = 0; i < n - 1; i++) { // this is creating the tree with the weights and their connections
		int a, b, r;
		cin >> a >> b >> r;
		g[a].push_back({b, r});
		g[b].push_back({a, r});
	}

	while (q--) { //questions
		cin >> k >> v;
		sol = 0;
		vector<bool> vS(n + 1);
		visited = vS; //resetting which ones we've gone to.

		dfs(v);

		cout << sol << '\n';
	}
}
