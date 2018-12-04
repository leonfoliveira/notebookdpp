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

// Matrix Multiplication

struct matrix {
    int mat[MAXN][MAXN];
};

int n;

matrix matMul(matrix a, matrix b) {
    matrix c;
    int k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (c.mat[i][j] = k = 0; k < n; k++)
                c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
    return c;
}

int main() {}