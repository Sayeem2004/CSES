#include <bits/stdc++.h>
using namespace std;
#define ll int64_t


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    map<ll,ll> m;
    ll curr = 0, ans = 0;
    for (ll i = 0; i < n; i++) {
        curr += v[i];
        ll x = (curr % n + n) % n;
        if (x == 0) ans++;
        ans += m[x];
        m[x]++;
    }
    cout << ans << "\n";
}
