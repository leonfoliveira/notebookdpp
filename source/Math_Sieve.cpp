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

// Sieve Of Eratosthenes

vi sieve(int n) {
    vb prime(n + 1, true);

    for (int p = 2; p * p <= n; p++)
        if (prime[p])
            for (int i = p * 2; i <= n; i += p)
                prime[i] = false;
    vi v;
    for (int p = 2; p <= n; p++)
        if (prime[p])
            v.pb(p);
    return v;
}

int main() {}