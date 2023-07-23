#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, X; std::cin >> N >> X;
    const int MOD = 1e9 + 7;

    std::vector<int> V(N);
    for (int &v : V) std::cin >> v;

    std::vector<std::vector<int>> DP(N + 1, std::vector<int>(X + 1, 0));
    for (int i = 1; i <= N; i++) DP[i][0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int q = 1; q <= X; q++) {
            int inc = q >= V[i-1] ? DP[i][q-V[i-1]] : 0LL;
            int exc = DP[i-1][q];
            DP[i][q] = (inc + exc) % MOD;
        }
    }

    std::cout << DP[N][X] << "\n";
}
