#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, M; std::cin >> N >> M;

    std::vector<std::vector<int>> DP(N+1, std::vector<int>(M+1, 1e9));
    for (int i = 0; i <= std::min(N, M); i++) DP[i][i] = 0;

    for (int i = 1; i <= N; i++) {
        for (int q = 1; q <= M; q++) {
            if (i == q) continue;

            for (int r = 1; r < i; r++)
                DP[i][q] = std::min(DP[i][q], DP[r][q] + DP[i-r][q] + 1);
            for (int r = 1; r < q; r++)
                DP[i][q] = std::min(DP[i][q], DP[i][r] + DP[i][q-r] + 1);
        }
    }

    std::cout << DP[N][M] << "\n";
}
