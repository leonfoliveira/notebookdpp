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

// Modular Exponentiation

int expmod(int a, int b, int p = 1e9+7) {
    int x = 1;
    a %= p;
    while (b > 0) {
        if (b & 1)
            x = (x * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return x;
}

int main() {}