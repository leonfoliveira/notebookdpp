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

// Coin-Change

int coins[MAXN];

int minCoins(int n, int w) {
    vi dp(w + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= w; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                int sub_res = dp[i - coins[j]];
                if (sub_res != INT_MAX && sub_res + 1 < dp[i])
                    dp[i] = sub_res + 1;
            }
        }
    }
    return dp[w];
}
// Total possibilities
int count(int n, int w) {
    if (!w)
        return 1;
    if (w < 0)
        return 0;
    if (n <= 0 && w >= 1)
        return 0;
    return count(n - 1, w) + count(n, w - coins[n - 1]);
}

int main() {}