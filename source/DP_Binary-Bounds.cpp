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

int v[MAXN], n;

int lower(int x) {

	int l = 0, r = n-1, mid;
	while (l < r) {
		mid = (l+r+1)/2;
		if (v[mid] <= x)
			l = mid;
		else
			r = mid-1;
	}
	return v[l] <= x ? l : -1;
}

int upper(int x) {

	int l = 0, r = n-1, mid;
	while (l < r) {
		mid = (l+r)/2;
		if (v[mid] >= x)
			r = mid;
		else
			l = mid+1;
	}
	return v[r] >= x ? r : -1;
}

int main() {}