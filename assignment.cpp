#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> edge; // node, weight

void dijkstra(vector<vector<edge>>& graph, int source, int destination, int n) {
    vector<int> dist(n, INT_MAX); // Distance from source to each node
    vector<int> parent(n, -1);    // To reconstruct the shortest path
    priority_queue<edge, vector<edge>, greater<edge>> pq; // Min-heap for shortest distance

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int curr = pq.top().second;
        pq.pop();

        for (auto neighbor : graph[curr]) {
            int nextNode = neighbor.first;
            int weight = neighbor.second;

            if (dist[curr] + weight < dist[nextNode]) {
                dist[nextNode] = dist[curr] + weight;
                pq.push({dist[nextNode], nextNode});
                parent[nextNode] = curr;
            }
        }
    }

    if (dist[destination] == INT_MAX) {
        cout << "No path found from " << source << " to " << destination << endl;
    } else {
        cout << "Shortest Distance from node " << source << " to node " << destination << " is " << dist[destination] << endl;

        vector<int> path;
        for (int v = destination; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());

        cout << "Path: ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<edge>> graph(n);

    // Hard-coded graph: each entry represents an edge (node, weight)
    graph[0].push_back({1, 10});
    graph[0].push_back({4, 3});
    graph[1].push_back({2, 1});
    graph[4].push_back({1, 4});
    graph[4].push_back({2, 8});
    graph[2].push_back({3, 5});

    int source, destination;
    cout << "Enter source node: ";
    cin >> source;
    cout << "Enter destination node: ";
    cin >> destination;

    dijkstra(graph, source, destination, n);

    return 0;
}