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

// Kadane

int v[MAXN];

int kadane() {
    int max = INT_MIN, temp = 0;
    for (int i : v) {
        temp += i;
        if (max < temp) max = temp;
        if (temp < 0) temp = 0;
    }
    return max;
}

int main() {}