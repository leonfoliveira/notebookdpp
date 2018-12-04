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

// Knapsack

int value[MAXN], weight[MAXN];

int knapsack(int n, int w) {
    int dp[n + 1][w + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (!i || !j)
                dp[i][j] = 0;
            else if (weight[i - 1] <= j)
                dp[i][j] = max(value[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][w];
}
// With repetitions
int unbKnapsack(int n, int w) {
    vi dp(w + 1);
    for (int i = 1; i <= w; i++)
        for (int j = 0; j < n; j++)
            if (weight[j] <= i)
                dp[i] = max(dp[i - weight[j]] + value[j], dp[i]);
    return dp[w];
}

int main() {}