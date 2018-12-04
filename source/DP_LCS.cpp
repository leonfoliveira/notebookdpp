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

// Longest Common Subsequence (LCS)

string s, t;

int lcs() {
    int n = s.size(), m = t.size();
    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (!i || !j)
                dp[i][j] = 0;
            else if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];

    /* int i = n, j = m, index = dp[n][m];
    string seq(n + 1, ’ ’);
    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            i--; j--; index--;
            seq[index] = s[i];
        } else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    return seq; */
}

int main() {}