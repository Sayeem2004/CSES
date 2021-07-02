#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    vector<vector<pair<ll,ll>>> A(n);
    for (int i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        A[a-1].push_back({b-1, c});
    }
    vector<ll> D(n, 1e18);
    vector<bool> V(n);
    priority_queue<pair<ll,ll>> Q;
    D[0] = 0;
    Q.push({0,0});
    while (!Q.empty()) {
        int a = Q.top().second; Q.pop();
        if (V[a]) continue;
        V[a] = true;
        for (auto x : A[a]) {
            int b = x.first , w = x.second;
            if (D[a]+w < D[b]) {
                D[b] = D[a]+w;
                Q.push({-D[b],b});
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << D[i] << " ";
    cout << "\n";
}
