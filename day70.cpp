#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int src;
    cin >> src;

    vector<int> dist(n, 1e9);
    dist[src] = 0;

    // Relax edges n-1 times
    for (int i = 0; i < n - 1; i++) {
        for (auto e : edges) {
            if (dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    // Check negative cycle
    for (auto e : edges) {
        if (dist[e.u] + e.w < dist[e.v]) {
            cout << "NEGATIVE CYCLE";
            return 0;
        }
    }

    for (int i = 0; i < n; i++)
        cout << dist[i] << " ";
}