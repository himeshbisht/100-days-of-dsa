#include <bits/stdc++.h>
using namespace std;

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
    queue<int> q;

    q.push(s);
    vis[s] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int v : adj[node]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}