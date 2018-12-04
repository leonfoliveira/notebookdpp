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

// Divisors

vi divisors(int n) {
	int maxP = sqrt(n) + 2;
	vi div;
	for (int i = 1; i <= maxP; i++) {
		if (n % i == 0) {
			div.pb(i);
			div.pb(n / i);
		}
	}
	return div;
}

int main() {

    vi div = divisors(9);
    for (int i : div)
        cout << i << endl;
}