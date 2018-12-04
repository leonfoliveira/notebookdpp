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

// Segment Tree

int v[MAXN], st[4 * MAXN]/*, lazy[4 * MAXN] */;

void build(int l, int r, int no = 0) {
    if (l > r) return;
    if (l == r) {
        st[no] = v[l];
        return;
    }

    int mid = l + (r - l) / 2;
    build(l, mid, no * 2 + 1);
    build(mid + 1, r, no * 2 + 2);
    st[no] = st[no * 2 + 1] + st[no * 2 + 2];
}

/* void prop(int l, int r, int no) {
    if (lazy[no] != 0) {
        st[no] += (r - l + 1) * lazy[no];
        if (l != r) {
            lazy[no * 2 + 1] += lazy[no];
            lazy[no * 2 + 2] += lazy[no];
        }
        lazy[no] = 0;
    }
} */

int query(int l, int r, int qs, int qe, int no = 0) {
    if (l > r || l > qe || r < qs) return 0;
    // prop(l, r, no);
    if (l >= qs && r <= qe) return st[no];
    int mid = l + (r - l) / 2;
    return query(l, mid, qs, qe, 2 * no + 1) + query(mid + 1, r, qs, qe, 2 * no + 2);
}

void update(int l, int r, int value, int pos, int no = 0) {
    if (l > pos || r < pos) return;
    st[no] += value;
    if (l == r) return;
    int mid = l + (r - l) / 2;
    update(l, mid, value, pos, no * 2 + 1);
    update(mid + 1, r, value, pos, no * 2 + 2);
}
/* void lazyUpdate(int l, int r, int qs, int qe, int value, int no = 0) {
    if (l > r || l > qe || r < qs) return;
    prop(l, r, no);
    if (l >= qs && r <= qe) {
        st[no] += (r - l + 1) * value;
        if (l != r) {
            lazy[no * 2 + 1] += value;
            lazy[no * 2 + 2] += value;
        }
        return;
    }
    int mid = l + (r - l) / 2;
    lazyUpdate(l, mid, qs, qe, value, no * 2 + 1);
    lazyUpdate(mid + 1, r, qs, qe, value, no * 2 + 2);
    st[no] = st[no * 2 + 1] + st[no * 2 + 2];
} */

int main() {}