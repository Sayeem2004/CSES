#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    std::string A, B; std::cin >> A >> B;
    int N = A.size(), M = B.size();

    std::vector<std::vector<int>> DP(N+1, std::vector<int>(M+1, 0));
    for (int i = 0; i <= N; i++) DP[i][0] = i;
    for (int i = 0; i <= M; i++) DP[0][i] = i;

    for (int i = 1; i <= N; i++) {
        for (int q = 1; q <= M; q++) {
            int lft = DP[i][q-1] + 1;
            int abv = DP[i-1][q] + 1;
            int dag = DP[i-1][q-1] + (A[i-1] != B[q-1]);

            DP[i][q] = std::min({lft, abv, dag});
        }
    }

    std::cout << DP[N][M] << "\n";
}
