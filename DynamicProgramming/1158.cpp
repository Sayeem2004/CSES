#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, mx; cin >> n >> mx;
    vector<int> m(n+1), p(n+1);
    for (int i = 1; i <= n; i++)
        cin >> m[i];
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    vector<vector<int>> dp(n+1,vector<int>(mx+1));
    for (int i = 0; i <= n; i++) {
        for (int q = 0; q <= mx; q++) {
            if (i == 0 || q == 0) {
                dp[i][q] = 0;
            } else {
                int temp = dp[i-1][q];
                int temp2 = (q < m[i]) ? 0 : p[i]+dp[i-1][q-m[i]];
                dp[i][q] = max(temp,temp2);
            }
        }
    }
    cout << dp[n][mx] << "\n";
}
