#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define ll long long
#define mk make_pair
#define pb push_back
#define MAXN 0

// Breadth-First Search (BFS)

int n;
vi graph[MAXN];

vi bfs(int src, int w = 1) {
    queue<int> q;
    vi dist(n, INT_MAX);
    vb vis(n);

    q.push(src);
    dist[src] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = true;
        for (int v : graph[u]) {
            if (!vis[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                q.push(v);
            }
        }
    }
    return dist;
}

int main() {}