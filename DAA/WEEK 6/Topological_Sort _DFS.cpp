#include <iostream>
#define MAX 100

using namespace std;

int adj[MAX][MAX];
bool visited[MAX];
int n, indegree[MAX], topOrder[MAX], index = 0;

void dfs(int u) {
    visited[u] = true;
    for (int v = 0; v < n; v++) {
        if (adj[u][v] == 1 && !visited[v]) {
            dfs(v);
        }
    }
    topOrder[index++] = u;
}

void topologicalSort() {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    cout << "Topological Sort Order: ";
    for (int i = n - 1; i >= 0; i--) {
        cout << topOrder[i] << " ";
    }
    cout << endl;
}

int main() {
    int m, u, v;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;
    for (int i = 0; i < m; i++) {
        cout << "Enter an edge: ";
        cin >> u >> v;
        adj[u][v] = 1;
        indegree[v]++;
    }
    topologicalSort();
    return 0;
}

