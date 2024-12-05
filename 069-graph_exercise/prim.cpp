#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

int primMST(vector<vector<pair<int, int>>>& graph, vector<pair<int, int>>& mst_edges) {
    int n = graph.size();
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    vector<int> parent(n, -1); // Track the parent of each node
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int cost = 0;
    pq.push({0, 0});
    dist[0] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;
        cost += w;

        // Add edge to MST if it's not the starting node
        if (parent[u] != -1) {
            mst_edges.push_back({parent[u], u});
        }

        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (!visited[v] && weight < dist[v]) {
                dist[v] = weight;
                parent[v] = u; // Update parent of v
                pq.push({dist[v], v});
            }
        }
    }
    return cost;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; ++i) {
        cout << "type graph: " << i << endl;
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<pair<int, int>> mst_edges; // To store the edges of the MST
    int minimum_cost = primMST(graph, mst_edges);

    cout << "Minimum Cost of MST: " << minimum_cost << endl;
    cout << "Edges in the MST:" << endl;
    for (auto& edge : mst_edges) {
        cout << edge.first << " - " << edge.second << endl;
    }

    return 0;
}
