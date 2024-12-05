#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <stack>
using namespace std;

const int INF = numeric_limits<int>::max();

vector<int> dijkstraShortestPath(vector<vector<pair<int, int>>>& graph, int source, int target) {
    int n = graph.size();
    vector<int> dist(n, INF);        // Store the shortest distance to each vertex
    vector<int> parent(n, -1);      // To reconstruct the shortest path
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap

    dist[source] = 0;               // Distance to the source is 0
    pq.push({0, source});           // Push the source with distance 0

    while (!pq.empty()) {
        int current_distance = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // If the shortest path to the target is found, stop
        if (u == target) break;

        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;    // Neighbor vertex
            int weight = neighbor.second; // Weight of the edge u-v

            // Relax the edge (u, v)
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight; // Update distance
                parent[v] = u;              // Update parent to reconstruct the path
                pq.push({dist[v], v});      // Push the updated distance to the priority queue
            }
        }
    }

    // Reconstruct the shortest path
    vector<int> path;
    for (int v = target; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    return path; // Return the shortest path as a vector
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);
    cout << "Enter edges (u, v, weight):\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // Since the graph is undirected
    }

    int source, target;
    cout << "Enter source and target vertices: ";
    cin >> source >> target;

    vector<int> shortest_path = dijkstraShortestPath(graph, source, target);

    if (shortest_path.size() == 1 && shortest_path[0] != target) {
        cout << "No path exists between " << source << " and " << target << endl;
    } else {
        cout << "Shortest path from " << source << " to " << target << ": ";
        for (int vertex : shortest_path) {
            cout << vertex << " ";
        }
        cout << endl;
    }

    return 0;
}
