int n;
// vector<int> parent;
vector<vector<pair<int, int>>> adj;

vector<int> dij(int s) {
    // parent.assign(n+1, -1);
    vector<int> dist(n + 1, INF);
    dist[s] = 0;
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    vector<bool> vis(n + 1, 0);
    pq.push({dist[s], s});

    while (!pq.empty()) {
        int u = pq.top()[1];
        pq.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto p : adj[u]) {
            int v = p.first;
            int w = p.second;
            if (!vis[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                // parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
