#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n + 1);

    // input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> visited(n + 1, 0);

    // min heap {weight, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, 1}); // start from node 1
    int totalWeight = 0;

    while (!pq.empty()) {
        pair<int,int> top = pq.top();
        pq.pop();

        int wt = top.first;
        int node = top.second;

        if (visited[node]) continue;

        visited[node] = 1;
        totalWeight += wt;

        for (auto it : adj[node]) {
            int nextNode = it.first;
            int nextWeight = it.second;

            if (!visited[nextNode]) {
                pq.push({nextWeight, nextNode});
            }
        }
    }

    cout << totalWeight;

    return 0;
}