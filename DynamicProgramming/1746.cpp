#include <bits/stdc++.h>
using namespace std;
#define ll int64_t


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    vector<ll> v(n+1);
    for (ll i = 1; i <= n; i++)
        cin >> v[i];
    vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));
    for (ll i = 1; i <= n; i++) {
        for (ll q = 1; q <= m; q++) {
            if (i == 1) {
                if (v[1] == 0 || v[1] == q)
                    dp[1][q] = 1;
            } else {
                if (v[i] == 0 || v[i] == q) {
                    if (q == 1) {
                        dp[i][q] = dp[i-1][q]+dp[i-1][q+1];
                        dp[i][q] %= 1000000007;
                    } else if (q == m) {
                        dp[i][q] = dp[i-1][q]+dp[i-1][q-1];
                        dp[i][q] %= 1000000007;
                    } else {
                        dp[i][q] = dp[i-1][q]+dp[i-1][q-1]+dp[i-1][q+1];
                        dp[i][q] %= 1000000007;
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= m; i++) {
        ans += dp[n][i];
        ans %= 1000000007;
    }
    cout << ans << "\n";
}
