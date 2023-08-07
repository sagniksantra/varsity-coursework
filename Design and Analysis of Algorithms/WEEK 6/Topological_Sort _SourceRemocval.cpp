#include <iostream>
using namespace std;
const int MAXN = 100;

int graph[MAXN][MAXN];
int indegree[MAXN];
int n;

void topologicalSort() {
    int output[MAXN], idx = 0;
    int i, j, k;
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            output[idx++] = i;
        }
    }
    for (i = 0; i < idx; i++) {
        k = output[i];
        std::cout << k << " ";
        for (j = 0; j < n; j++) {
            if (graph[k][j] == 1) {
                indegree[j]--;
                if (indegree[j] == 0) {
                    output[idx++] = j;
                }
            }
        }
    }
}

int main() {
    int m, u, v;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;
    for (int i = 0; i < m; i++) {
        cout << "Enter an edge (u v): ";
        cin >> u >> v;
        graph[u][v] = 1;
        indegree[v]++;
    }
    cout << "Topological Sort: ";
    topologicalSort();
    cout <<endl;
    return 0;
}

