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

// Polygon Area

int n;
double x[MAXN], y[MAXN];

double area() {
    double total = 0;
    int j = n - 1;
    for (int i = 0; i < n; i++) {
        total += (x[j] + x[i]) * (y[j] + y[i]);
        j = i;
    }
    return (total >= 0) ? (total / 2) : (-total / 2);
}

int main() {}