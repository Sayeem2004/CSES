#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, X; std::cin >> N >> X;
    const int MOD = 1e9+7;

    std::vector<int> V(N);
    for (int &v : V) std::cin >> v;

    std::vector<std::vector<int>> DP(N, std::vector<int>(X+1, 0));
    for (int i = 1; i <= X; i++) DP[0][i] = (V[0] == 0 || V[0] == i ? 1 : 0);

    for (int i = 1; i < N; i++) {
        for (int q = 1; q <= X; q++) {
            if (V[i] == 0 || V[i] == q) {
                int neg = q > 0 ? DP[i-1][q-1] : 0;
                int zer = DP[i-1][q];
                int pos = q < X ? DP[i-1][q+1] : 0;

                DP[i][q] = ((neg + zer) % MOD + pos) % MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= X; i++) {
        ans = (ans + DP[N-1][i]) % MOD;
    }

    std::cout << ans << "\n";
}
