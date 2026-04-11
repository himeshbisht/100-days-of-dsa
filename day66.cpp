#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, vector<int> adj[], vector<bool>& vis, vector<bool>& rec) {
    vis[node] = true;
    rec[node] = true;

    for (int neighbor : adj[node]) {
        if (!vis[neighbor] && dfs(neighbor, adj, vis, rec))
            return true;
        else if (rec[neighbor])
            return true;
    }

    rec[node] = false;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<bool> vis(n, false), rec(n, false);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (dfs(i, adj, vis, rec)) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
}