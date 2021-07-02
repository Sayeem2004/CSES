#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define arr array

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vector<ll> S(n), E(n), C(n);
    map<ll, ll> P;
    for (int i = 0; i < n; i++) {
        ll a, b, c; cin >> a >> b >> c;
        S[i] = a;
        E[i] = b+1;
        C[i] = c;
        P[S[i]] = 0;
        P[E[i]] = 0;
    }
    ll cnt = 0;
    for (auto x : P) {
        P[x.first] = cnt;
        cnt++;
    }
    vector<vector<arr<ll,2>>> V(cnt);
    for (int i = 0; i < n; i++) {
        V[P[E[i]]].push_back({P[S[i]], C[i]});
    }
    vector<ll> dp(cnt);
    for (int i = 0; i < cnt; i++) {
        if (i != 0) dp[i] = dp[i-1];
        for (auto v : V[i]) {
            dp[i] = max(dp[i], dp[v[0]]+v[1]);
        }
    }
    cout << dp[cnt-1] << "\n";
}
