#include <bits/stdc++.h>
using namespace std;
#define ll long long
int MOD = 1000000007;

int main() {
    ll n; cin >> n;
    ll ans = 0;
    for (ll s = 1, e; s <= n; s = e+1) {
        ll f = n/s;
        e = n/f;
        ll sm1 = (e-s+1);
        ll sm2 = (e+s);
        if (sm1 % 2 == 0) sm1 /= 2;
        else sm2 /= 2;
        sm1 %= MOD;
        sm2 %= MOD;
        ll sm = (sm1 * sm2) % MOD;
        ans += (f*sm)%MOD;
        ans %= MOD;
    }
    cout << ans << "\n";
}
