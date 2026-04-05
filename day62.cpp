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
        adj[v].push_back(u); // remove for directed graph
    }

    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int x : adj[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
}