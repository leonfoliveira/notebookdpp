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

// Factoring

vi factorize(int n) {
    vi v;
    for(int i = 2; i * i <= n; i++) {
        if (n % i) continue;
        v.pb(i);
        n /= i--;
    }
    if (n > 1) v.pb(n);
    return v;
}

int main() {}