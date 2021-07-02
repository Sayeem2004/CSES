#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vector<ll> V(n);
    ll sm = 0;
    for (int i = 0; i < n; i++) {
        cin >> V[i];
        sm += V[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        dp[i][i] = V[i];
    }
    for (int i = n-1; i >= 0; i--) {
        for (int q = 0; q < n; q++) {
            if (i == q) continue;
            if (q != 0 && i != n-1)
                dp[i][q] = max(V[i]-dp[i+1][q],V[q]-dp[i][q-1]);
        }
    }
    cout << (sm+dp[0][n-1])/2 << "\n";
}
