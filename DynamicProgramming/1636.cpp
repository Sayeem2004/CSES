#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, x; cin >> n >> x;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    for (int i = 1; i <= n; i++) {
        for (int q = 0; q <= x; q++) {
            if (q == 0) {
                dp[i][q] = 1;
            } else {
                int a = (v[i] > q) ? 0 : dp[i][q-v[i]];
                int b = (i == 1) ? 0 : dp[i-1][q];
                dp[i][q] = (a+b)%(1000000007);
            }
        }
    }
    cout << dp[n][x] << "\n";
}
