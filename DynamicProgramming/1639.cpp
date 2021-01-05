#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string a, b; cin >> a >> b;
    int c = a.size(), d = b.size();
    vector<vector<int>> dp(c+1,vector<int>(d+1));
    for (int i = 0; i <= c; i++)
        dp[i][0] = i;
    for (int i = 0; i <= d; i++)
        dp[0][i] = i;
    for (int i = 1; i <= c; i++) {
        for (int q = 1; q <= d; q++) {
            dp[i][q] = max(abs(i-q),min(dp[i-1][q-1],min(dp[i-1][q],dp[i][q-1])));
            if (dp[i][q] == dp[i-1][q-1])
                dp[i][q] -= a[i-1] == b[q-1];
            dp[i][q]++;
        }
    }
    cout << dp[c][d] << "\n";
}
