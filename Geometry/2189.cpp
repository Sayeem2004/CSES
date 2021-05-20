#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) {
        ll x1, y1, x2, y2, x3, y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        x2 -= x1; x3 -= x1;
        y2 -= y1; y3 -= y1;
        ll a = y3*x2 - x3*y2;
        if (a < 0) cout << "RIGHT\n";
        else if (a > 0) cout << "LEFT\n";
        else cout << "TOUCH\n";
    }
}
