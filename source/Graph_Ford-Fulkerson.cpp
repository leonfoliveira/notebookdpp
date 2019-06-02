#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pb push_back
#define MAXN 1000

int n, flow[MAXN][MAXN], parent[MAXN];
vector<int> graph[MAXN];

bool bfs(int src, int snk) {
    memset(parent, -1, sizeof parent);
    queue<int> q;

    parent[src] = -2;
    q.push(src);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
            if (parent[v] == -1 && flow[u][v]) {
                parent[v] = u;
                if (v == snk) return true;
                q.push(v);
            }
        }
    }
    return false;
}

int ford(int src, int snk) {
    int max_flow = 0;
    while (bfs(src, snk)) {
        int path_flow = INT_MAX;
        for (int v = snk; v != src; v = parent[v])
            path_flow = min(path_flow, flow[parent[v]][v]);

        for (int v = snk; v != src; v = parent[v]) {
            flow[parent[v]][v] -= path_flow;
            flow[v][parent[v]] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int main() {

    int matrix[][6] = { {0, 16, 13, 0, 0, 0}, 
                        {0, 0, 10, 12, 0, 0}, 
                        {0, 4, 0, 0, 14, 0}, 
                        {0, 0, 9, 0, 0, 20}, 
                        {0, 0, 0, 7, 0, 4}, 
                        {0, 0, 0, 0, 0, 0} 
                      }; 
    
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++) {
            if (matrix[i][j])
                graph[i].pb(j);
            flow[i][j] = matrix[i][j];
        }

    cout << ford(0, 5) << endl;
}