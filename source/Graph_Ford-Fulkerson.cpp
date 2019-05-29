#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define ll long long
#define mk make_pair
#define pb push_back
#define MAXN 100

int graph[MAXN][MAXN], parent[MAXN], n;

bool bfs(int src, int snk) {
    vb vis(n);
    queue<int> q;
    q.push(src);
    parent[src] = -1;
    vis[src] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = true;
        for (int v = 0; v < n; v++)
            if (!vis[v] && graph[u][v]) {
                q.push(v);
                parent[v] = u;
                vis[v] = true;
            }
    }
    return vis[snk];
}

int ford(int src, int snk) {
    int flow = 0;
    while (bfs(src, snk)) {
        int path_flow = INT_MAX;
        for (int v = snk; v != src; v = parent[v])
            path_flow = min(path_flow, graph[parent[v]][v]);

        for (int v = snk; v != src; v = parent[v]) {
            graph[parent[v]][v] -= path_flow;
            graph[v][parent[v]] += path_flow;
        }
        flow += path_flow;
    }
    return flow;
}

int main() {

    n = 6;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
    graph[0][1] = 16;
    graph[0][2] = 13;
    graph[1][2] = 10;
    graph[1][3] = 12;
    graph[2][1] = 4;
    graph[2][4] = 14;
    graph[3][2] = 9;
    graph[3][5] = 20;
    graph[4][3] = 7;
    graph[4][5] = 4;

    cout << ford(0, 5) << endl;
}