#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define arr array

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, m, k; cin >> n >> m >> k;
    vector<vector<arr<ll,2>>> A(n);
    for (int i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        A[a-1].push_back({b-1,c});
    }
    vector<priority_queue<ll>> D(n);
    priority_queue<arr<ll,2>> Q;
    D[0].push(0); Q.push({0,0});
    while (!Q.empty()) {
        arr<ll,2> v = Q.top(); Q.pop();
        ll d = -v[0];
        if (d > D[v[1]].top()) continue;
        for (auto x : A[v[1]]) {
            ll nd = d+x[1];
            if (D[x[0]].size() < k) {
                D[x[0]].push(nd);
                Q.push({-nd, x[0]});
            } else if (nd < D[x[0]].top()) {
                D[x[0]].push(nd);
                D[x[0]].pop();
                Q.push({-nd, x[0]});
            }

        }
    }
    vector<ll> C(k);
    for (int i = 0; i < k; i++) {
        C[k-i-1] = D[n-1].top();
        D[n-1].pop();
    }
    for (auto c : C)
        cout << c << " ";
}
