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

// Dijkstra

int n;
vii graph[MAXN];

vi dijkstra(int src) {
    priority_queue<ii, vii, greater<ii>> pq;
    vi dist(n, INT_MAX);
    vb vis(n, false);

    pq.push(mk(0, src));
    dist[src] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        vis[u] = true;
        for (ii i : graph[u]) {
            int v = i.first;
            int w = i.second;
            if (!vis[v] && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(mk(dist[v], v));
            }
        }
    }
    return dist;
}

int main() {}