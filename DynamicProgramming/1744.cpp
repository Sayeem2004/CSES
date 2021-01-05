#include <bits/stdc++.h>
using namespace std;
#define ll int64_t


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a, b; cin >> a >> b;
    int dp[a+1][b+1];
    for (int l = 1; l <= a; l++) {
        for (int w = 1; w <= b; w++) {
            if (l == w) dp[l][w] = 0;
            else {
                int mn = 1e9;
                for (int i = 1; i < l; i++)
                    mn = min(mn,1+dp[l-i][w]+dp[i][w]);
                for (int i = 1; i < w; i++)
                    mn = min(mn,1+dp[l][w-i]+dp[l][i]);
                dp[l][w] = mn;
            }
        }
    }
    cout << dp[a][b] << "\n";
}
