#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, X; std::cin >> N >> X;

    std::vector<int> PR(N), PG(N);
    for (int &pr : PR) std::cin >> pr;
    for (int &pg : PG) std::cin >> pg;

    std::vector<std::vector<int>> DP(N + 1, std::vector<int>(X + 1, 0));
    for (int i = 0; i <= N; i++) {
        for (int q = 0; q <= X; q++) {
            if (i == 0 || q == 0) continue;

            int inc = q >= PR[i-1] ? PG[i-1] + DP[i-1][q - PR[i-1]] : 0;
            int exc = i > 0 ? DP[i-1][q] : 0;
            DP[i][q] = std::max(inc, exc);
        }
    }

    std::cout << DP[N][X] << "\n";
}
