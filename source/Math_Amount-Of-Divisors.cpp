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

// Amount of Divisors

vi amount(int n) {
	vi v(n + 1);
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j += i)
			v[j]++;
	return v;
}

int main () {}