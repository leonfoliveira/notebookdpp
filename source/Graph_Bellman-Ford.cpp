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

// Bellman-Ford

struct edge {
    int u, v, w;
    edge() {};
    edge(int _u, int _v, int _w) {
        u = _u, v = _v, w = _w;
    }
};

int n, m;
vector<edge> graph;

bool bellman(int src) {
    vi dist(n, INT_MAX);

    dist[src] = 0;
    for (int i = 0; i < n - 1; i++)
        for (edge e : graph)
            if (dist[e.u] != INT_MAX)
                dist[e.v] = min(dist[e.u] + e.w, dist[e.v]);
    for (edge e : graph)
        if (dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v])
            return true;
    return false;
}

int main() {}