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

// Greatest Common Divisor

int gcd(int x, int y) {
    return y ? gcd(y, x % y) : abs(x);
}

int main() {}