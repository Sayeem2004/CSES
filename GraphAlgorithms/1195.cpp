#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define arr array

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<arr<ll,2>>> A(n), R(n);
    vector<arr<ll,3>> E(m);
    for (int i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        E[i] = {a-1,b-1,c};
        A[a-1].push_back({b-1,c});
        R[b-1].push_back({a-1,c});
    }
    vector<ll> D1(n, 1e18), V1(n, 0);
    priority_queue<arr<ll,2>> Q1;
    D1[0] = 0;
    Q1.push({0,0});
    while (!Q1.empty()) {
        ll a = Q1.top()[1]; Q1.pop();
        if (V1[a]) continue;
        V1[a] = 1;
        for (auto x : A[a]) {
            ll b = x[0], c = x[1];
            if (D1[a]+c < D1[b]) {
                D1[b] = D1[a]+c;
                Q1.push({-D1[b],b});
            }
        }
    }
    vector<ll> D2(n, 1e18), V2(n, 0);
    priority_queue<arr<ll,2>> Q2;
    D2[n-1] = 0;
    Q2.push({0,n-1});
    while (!Q2.empty()) {
        ll a = Q2.top()[1]; Q2.pop();
        if (V2[a]) continue;
        V2[a] = 1;
        for (auto x : R[a]) {
            ll b = x[0], c = x[1];
            if (D2[a]+c < D2[b]) {
                D2[b] = D2[a]+c;
                Q2.push({-D2[b],b});
            }
        }
    }
    ll ans = 1e18;
    for (auto e : E)
        ans = min(ans, D1[e[0]]+e[2]/2+D2[e[1]]);
    cout << ans << "\n";
}
