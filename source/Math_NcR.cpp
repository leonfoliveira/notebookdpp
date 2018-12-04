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

// N Choose R

int ncrDp(int n, int r, int p) {
    vi dp(r + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = min(i, r); j > 0; j--)
            dp[j] = (dp[j] + dp[j - 1]) % p;
    return dp[r];
}

int ncr(int n, int r, int p) {
    if (!r)
        return 1;
    return (ncr(n / p, r / p, p) * ncrDp(n % p, r % p, p)) % p;
}

int main() {}