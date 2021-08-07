#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

// Binary Exponentiation
ll modpow(ll x, ll n, ll m) {
    if (n == 0) return 1 % m;
    ll u = modpow(x, n/2, m);
    u = (u * u) % m;
    if (n % 2 == 1) u = (u * x) % m;
    return u;
}

ll dc(ll n) {
    ll sum = 0;
    ll i, q;
    for (i = 1, q = 1; i*10 <= n; i *= 10, q++) {
        sum += 9 * q * modpow(10, q-1, (ll)1e18);
    }
    sum += (n-i+1) * q;
    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t; cin >> t; while (t--) {
        ll n; cin >> n;
        ll l = 1, r = 1e17;
        while (l < r) {
            ll mid = (l+r)/2;
            ll sum = dc(mid);
            if (sum >= n) r = mid-1;
            if (sum < n) l = mid+1;
        }
        ll ans = (l+r)/2;
        string s = to_string(ans) + to_string(ans+1);
        ll curr = dc(ans-1);
        cout << s[n-curr-1] << "\n";
    }
}
