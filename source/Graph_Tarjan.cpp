#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define ll long long
#define mk make_pair
#define pb push_back
#define MAXN 1000

int n, disc[MAXN], low[MAXN], scc[MAXN], ct, id;
vi graph[MAXN];
stack<int> st;
bool onstack[MAXN];

void dfs(int u) {
    disc[u] = low[u] = ct++;
    st.push(u);
    onstack[u] = true;

    for (int v : graph[u]) {
        if (disc[v] == -1) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (onstack[v])
            low[u] = min(low[u], disc[v]);
    }

    if (low[u] == disc[u]) {
        int v;
        do {
            v = st.top();
            st.pop();
            onstack[v] = false;
            scc[v] = id;
        } while (u != v);
        id++;
    }
}

void tarjan() {
    ct = id = 0;
    memset(disc, -1, sizeof disc);

    for (int i = 0; i < n; i++)
        if (disc[i] == -1)
            dfs(i);
}

int main() {

    int k, u, v;
    scanf("%d %d", &n, &k);
    while (k--) {
        scanf("%d %d", &u, &v);
        graph[u].pb(v);
    }
    tarjan();
    for (int i = 0; i < n; i++) {
        printf("%d\n", scc[i]);
    }
}
