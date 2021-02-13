#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll md = 1000000007;
    int t; cin >> t;
    int mx = 0;
    vector<int> pos(t);
    for (int i = 0; i < t; i++) {
        int n; cin >> n;
        mx = max(mx,n);
        pos[i] = n;
    }
    vector<array<ll,2>> dp(mx+1);
    // 0 = cut, 1 = uncut
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= mx; i++) {
        dp[i][0] = 4 * dp[i-1][0] + dp[i-1][1];
        dp[i][0] %= md;
        dp[i][1] = dp[i-1][0] + 2 * dp[i-1][1];
        dp[i][1] %= md;
    }
    for (int i = 0; i < t; i++) {
        cout << ((dp[pos[i]][0]+dp[pos[i]][1]) % md) << "\n";
    }
}
