#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N; std::cin >> N;
    const int MOD = 1e9 + 7;

    std::vector<std::vector<int>> DP(N, std::vector<int>(N, 0));
    DP[0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int q = 0; q < N; q++) {
            char c; std::cin >> c;
            if (c == '*') DP[i][q] = -1;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int q = 0; q < N; q++) {
            if (DP[i][q] == -1 || (i == 0 && q == 0)) continue;

            int abv = i > 0 ? std::max(DP[i - 1][q], 0) : 0;
            int lft = q > 0 ? std::max(DP[i][q - 1], 0) : 0;
            DP[i][q] = (abv + lft) % MOD;
        }
    }

    std::cout << std::max(DP[N - 1][N - 1], 0) << "\n";
}
