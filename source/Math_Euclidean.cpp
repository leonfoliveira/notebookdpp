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

// Extended Euclidean Algorithm

int egcd(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0, y = 1;
        return b;
    }
    int xo, yo;
    int gcd = egcd(b % a, a, xo, yo);
    x = yo - (b / a) * xo;
    y = xo;
    if (gcd < 0)
        gcd = -gcd, x = -x, y = -y;
    return gcd;
}

int main() {}