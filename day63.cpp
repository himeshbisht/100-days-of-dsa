#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis) {
    vis[node] = 1;
    cout << node << " ";

    for (int v : adj[node]) {
        if (!vis[v]) {
            dfs(v, adj, vis);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    int s;
    cin >> s;

    vector<int> vis(n, 0);

    dfs(s, adj, vis);
}