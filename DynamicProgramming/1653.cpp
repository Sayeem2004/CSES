#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define arr array

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, x; cin >> n >> x;
    vector<int> V(n);
    for (int i = 0; i < n; i++)
        cin >> V[i];
    vector<arr<int,2>> DP(1<<n);
    DP[0] = {1,0};
    for (int i = 1; i < (1<<n); i++) {
        DP[i] = {n+1,0};
        for (int q = 0; q < n; q++) {
            if (i & (1 << q)) {
                auto prev = DP[i ^ (1 << q)];
                if (prev[1]+V[q] <= x) {
                    prev[1] += V[q];
                } else {
                    prev[0]++;
                    prev[1] = V[q];
                }
                DP[i] = min(DP[i], prev);
            }
        }
    }
    cout << DP[(1<<n)-1][0] << "\n";
}
