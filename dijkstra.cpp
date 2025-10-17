// dijkstra.cpp
// Dijkstra's Algorithm - shortest path from source to all nodes
// Compile: g++ -std=c++17 dijkstra.cpp -O2 -o dijkstra
// Example: ./dijkstra

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL<<60);

vector<ll> dijkstra(int n, int src, const vector<vector<pair<int,int>>>& adj) {
    vector<ll> dist(n, INF);
    dist[src] = 0;
    // {distance, node}
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example graph:
    // n = 6, edges (u,v,w):
    // 0-1(7), 0-2(9), 0-5(14), 1-2(10), 1-3(15),
    // 2-3(11), 2-5(2), 3-4(6), 4-5(9)
    int n = 6;
    vector<vector<pair<int,int>>> adj(n);
    auto addEdge = [&](int u, int v, int w) {
        adj[u].push_back({v,w});
        adj[v].push_back({u,w}); // undirected; remove if directed
    };

    addEdge(0,1,7);
    addEdge(0,2,9);
    addEdge(0,5,14);
    addEdge(1,2,10);
    addEdge(1,3,15);
    addEdge(2,3,11);
    addEdge(2,5,2);
    addEdge(3,4,6);
    addEdge(4,5,9);

    int src = 0;
    auto dist = dijkstra(n, src, adj);
    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) cout << i << ": INF\n";
        else cout << i << ": " << dist[i] << '\n';
    }
    return 0;
}
