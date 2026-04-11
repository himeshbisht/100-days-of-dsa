#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // adjacency list: {neighbor, weight}
    vector<pair<int,int>> adj[n];

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove this line if graph is directed
    }

    int src;
    cin >> src;

    vector<int> dist(n, 1e9);
    dist[src] = 0;

    // min heap {distance, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node]) {
            int neighbor = it.first;
            int weight = it.second;

            if (d + weight < dist[neighbor]) {
                dist[neighbor] = d + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    // print shortest distances
    for (int i = 0; i < n; i++) {
        cout << "Distance from " << src << " to " << i << " = " << dist[i] << endl;
    }

    return 0;
}