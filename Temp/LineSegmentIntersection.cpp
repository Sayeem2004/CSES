#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

struct Point {
    ll x, y;

    Point() {
        cin >> x >> y;
    }

    ll cprod(Point l, Point r) {
        return (r.x-x)*(l.y-y) - (l.x-x)*(r.y-y);
    }
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) {
        Point p1 = Point();
        Point p2 = Point();
        Point p3 = Point();
        Point p4 = Point();
        ll cp1 = p3.cprod(p1, p2);
        ll cp2 = p4.cprod(p1, p2);
        if ((cp1 >= 0 && cp2 <= 0) || (cp1 <= 0 && cp2 >= 0)) cout << "YES\n";
        else cout << "NO\n";
    }
}
