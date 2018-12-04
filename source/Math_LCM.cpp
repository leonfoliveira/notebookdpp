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

// Least Common Multiple

int lcm(int x, int y) {
    if (x && y) return abs(x) / gcd(x, y) * abs(y);
    return abs(x | y);
}

int main() {}