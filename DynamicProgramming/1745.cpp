#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int sm = 0;
    vector<int> V(n);
    for (int i = 0; i < n; i++) {
        cin >> V[i];
        sm += V[i];
    }
    vector<vector<bool>> dp(n+1, vector<bool>(sm+1));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int q = 0; q <= sm; q++) {
            dp[i][q] = dp[i-1][q];
            if (V[i-1] <= q)
                dp[i][q] = dp[i][q] || dp[i-1][q-V[i-1]];
        }
    }
    vector<int> ans;
    for (int q = 1; q <= sm; q++) {
        if (dp[n][q]) ans.push_back(q);
    }
    cout << ans.size() << "\n";
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}
