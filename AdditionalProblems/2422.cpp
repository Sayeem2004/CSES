#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

bool check(ll m, ll n) {
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
        ans += min(n,m/i);
    return (ans >= (n*n+1)/2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    ll l = 1, r = n*n;
    while (l < r) {
        ll m = (l+r)/2;
        if (check(m, n)) r = m;
        else l = m+1;
    }
    cout << (l+r)/2 << "\n";
}
