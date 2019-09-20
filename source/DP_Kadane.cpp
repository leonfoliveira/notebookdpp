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

int v[MAXN], n;

int kadane() {
	int ans = v[0], temp = v[0];
	for (int i = 1; i < n; i++) {
		temp = max(v[i], temp+v[i]);
		ans = max(ans, temp);
	}
	return ans;
}

int main() {}