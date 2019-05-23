#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define ll long long
#define mk make_pair
#define pb push_back
#define INF 1000000
#define MAXN 100

int n, bit[MAXN], v[MAXN];

int query(int i) {
    int sum = 0;
    for (; i > 0; i -= i & (-i))
        sum += bit[i];
    return sum;
}

void update(int i, int value) {
    for (; i <= n; i += i & (-i))
        bit[i] += value;
}

void build() {
    memset(bit, 0, sizeof bit);
    for (int i = 1; i <= n; i++)
        update(i, v[i-1]);
}

int main() {

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    build();

    int i, j;
    scanf("%d %d", &i, &j);
    printf("Sum to from %d to %d: %d\n", i, j, query(j) - query(i));
}