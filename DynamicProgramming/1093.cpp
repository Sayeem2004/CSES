#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define mod 1000000007

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int sm = 0;
    for (int i = 1; i <= n; i++)
        sm += i;
    if (sm % 2 == 1) {
        cout << 0 << "\n";
        return 0;
    }
    sm /= 2;
    vector<vector<ll>> dp(n, vector<ll>(sm+1,0));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int q = 0; q <= sm; q++) {
            dp[i][q] = dp[i-1][q];
            if (q >= i)
                dp[i][q] += dp[i-1][q-i];
            dp[i][q] %= mod;
        }
    }
    cout << dp[n-1][sm] << "\n";
}
