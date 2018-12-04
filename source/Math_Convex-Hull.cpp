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

// Convex Hull

struct Point {
    int x, y;
    Point () {}
    Point (int _x, int _y) {
        x = _x, y = _y;
    }
};

int n;
Point points[MAXN], p0;

Point nextToTop(stack<Point> &S) {
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}

int distSq(Point p1, Point p2) {
    return pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2);
}
  
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0)? 1 : 2;
}

int compare(Point a, Point b) {
    int o = orientation(p0, a, b);
    if (!o)
        return (distSq(p0, b) >= distSq(p0, a));
    return (o == 2);
}

double convexHull() {
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++) {
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }

    swap(points[0], points[min]);

    p0 = points[0];
    sort(points + 1, points + n, compare);

    int m = 1;
    for (int i = 1; i < n; i++) {
        while (i < n-1 && !orientation(p0, points[i], points[i+1]))
            i++;
        points[m++] = points[i];
    }

    if (m < 3) return 0;

    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    for (int i = 3; i < m; i++) {
        while (orientation(nextToTop(S), S.top(), points[i]) != 2)
            S.pop();
        S.push(points[i]);
    }

    double total = 0;
    Point ant = S.top(), prim = S.top();
    S.pop();
    while (!S.empty()) {
        total += sqrt(distSq(S.top(), ant));
        ant = S.top();
        S.pop();
    }
    total += sqrt(distSq(ant, prim));
    return total;
}

int main() {}