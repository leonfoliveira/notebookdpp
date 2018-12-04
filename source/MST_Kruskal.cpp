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

// Kruskal

struct edge {
    int u, v, w;
    edge() {};
    edge(int _u, int _v, int _w) {
        u = _u, v = _v, w = _w;
    }
    bool operator < (const edge &b) const {
        return w < b.w;
    }
};

int n, root[MAXN];
vector<edge> graph;

int findset(int u) {
    return root[u] == u ? u : root[u] = findset(root[u]);
}

void initset() {
    for (int i = 0; i < n; i++) root[i] = i;
}

int kruskal() {
    initset();
    sort(graph.begin(), graph.end());
    vi tree[n];

    int total = 0;
    for (edge i : graph) {
        int u = i.u, v = i.v, w = i.w;

        int fu = findset(u);
        int fv = findset(v);
        if (fu != fv) {
            root[fu] = fv;
            total += w;
            tree[u].pb(v);
        }
    }
    return total;
}

int main() {}