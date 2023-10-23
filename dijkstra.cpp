#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int to;
    int weight;
};

class Graph {
public:
    int V; // Number of vertices
    vector<vector<Edge>> adj;

    Graph(int V) : V(V) {
        adj.resize(V);
    }

    void addEdge(int from, int to, int weight) {
        Edge e1 = {to, weight};
        adj[from].push_back(e1);
    }

    void shortestPathWithMinEdges(int source, int target) {
        vector<int> distance(V, INT_MAX);
        vector<int> minEdges(V, INT_MAX);
        vector<int> parent(V, -1);

        distance[source] = 0;
        minEdges[source] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, source});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (const Edge& e : adj[u]) {
                int v = e.to;
                int weight = e.weight;

                if (distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    minEdges[v] = minEdges[u] + 1;
                    parent[v] = u;
                    pq.push({distance[v], v});
                } else if (distance[u] + weight == distance[v] && minEdges[u] + 1 < minEdges[v]) {
                    minEdges[v] = minEdges[u] + 1;
                    parent[v] = u;
                    pq.push({distance[v], v});
                }
            }
        }

        if (distance[target] == INT_MAX) {
            cout << "No path exists from source to target." << endl;
            return;
        }

        cout << "Shortest Path from " << source << " to " << target << ":" << endl;
        int current = target;
        vector<int> path;
        while (current != -1) {
            path.push_back(current);
            current = parent[current];
        }

        cout << "Path: ";
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << " ";
        }
        cout << endl;

        cout << "Distance: " << distance[target] << endl;
        cout << "Minimum Edges: " << minEdges[target] << endl;
    }
};

int main() {
    int V = 6;
    Graph g(V);

    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(4, 5, 1);

    int source = 0;
    int target = 5;

    g.shortestPathWithMinEdges(source, target);

    return 0;
}
