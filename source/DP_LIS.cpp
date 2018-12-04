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

// Longest Increasing Subsequence (LIS)

int n, v[MAXN];

int lis() {
    if (!n)
        return 0;
    vi tail(n), prev(n, -1);
    int len = 1;

    for (int i = 1; i < n; i++) {
        if (v[i] < v[tail[0]])
            tail[0] = i;
        else if (v[i] > v[tail[len - 1]]){
            prev[i] = tail[len - 1];
            tail[len++] = i;
        } else {
            int pos = distance(tail.begin(), upper_bound(tail.begin(), tail.begin() + len - 1, v[i]));
            prev[i] = tail[pos - 1];
            tail[pos] = i;
        }
    }
    return len;
}

int main() {}