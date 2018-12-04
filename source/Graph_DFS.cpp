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

// Depth-First Search (DFS)

int n;
vi graph[MAXN];
bool vis[MAXN];

void dfs(int u) {
    vis[u] = true;
    for (int v : graph[u])
        if (!vis[v])
            dfs(v);
}

int main() {}