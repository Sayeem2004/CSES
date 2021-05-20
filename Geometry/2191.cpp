#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

ll crossproduct(ll x1, ll y1, ll x2, ll y2) {
    return (y2*x1) - (x2*y1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<pair<ll,ll>> P(n);
    for (int i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        P[i] = make_pair(x,y);
    }
    ll sm = 0;
    for (int i = 0; i < n-1; i++) {
        sm += crossproduct(P[i].first,P[i].second,P[i+1].first,P[i+1].second);
    }
    sm += crossproduct(P[n-1].first,P[n-1].second,P[0].first,P[0].second);
    cout << abs(sm) << "\n";
}
