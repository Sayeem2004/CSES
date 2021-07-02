#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

ll check(ll mx, ll m, vector<ll> V) {
    if (mx > m) return 1e18;
    ll cnt = 1, curr = 0;
    for (int i = 0; i < V.size(); i++) {
        if (curr + V[i] > m) {
            curr = V[i];
            cnt++;
        } else curr += V[i];
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, k; cin >> n >> k;
    vector<ll> V(n);
    ll mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> V[i];
        mx = max(V[i],mx);
    }
    ll l = 1, r = 1e18;
    while (l < r) {
        ll m = (l+r)/2;
        ll cnt = check(mx, m, V);
        if (cnt <= k) {
            if (check(mx, m-1, V) <= k) r = m-1;
            else r = m;
        } else l = m+1;
    }
    cout << (l+r)/2 << "\n";
}
