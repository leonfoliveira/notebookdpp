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

// Merge-Sort

int merge(int v[], int l, int r) {
    if (r == l)
        return 0;
    int invs = 0, mid = l + (r - l) / 2;

    invs += merge(v, l, mid);
    invs += merge(v, ++mid, r);

    int i = l, j = mid;
    queue<int> temp;

    while (i <= mid - 1 && j <= r) {
        if (v[i] <= v[j])
            temp.push(v[i++]);
        else {
            temp.push(v[j++]);
            invs += (mid - i);
        }
    }
    while (i <= mid - 1)
        temp.push(v[i++]);
    while (j <= r)
        temp.push(v[j++]);
    for (i = l; i <= r; i++) {
        v[i] = temp.front();
        temp.pop();
    }
    return invs;
}

int main() {}