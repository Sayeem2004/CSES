#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long N; std::cin >> N;
    long long SM = 0;

    std::vector<long long> V(N);
    for (long long &v : V) { std::cin >> v; SM += v; }

    std::vector<std::vector<long long>> DP(N, std::vector<long long>(N, 0));
    for (int i = 0; i < N; i++) DP[i][i] = V[i];

    for (int i = N-1; i >= 0; i--) {
        for (int q = 0; q < N; q++) {
            if (i >= q) continue;

            long long inc = i < N-1 ? V[i] - DP[i+1][q] : 0;
            long long dec = q > 0 ? V[q] - DP[i][q-1] : 0;
            DP[i][q] = std::max(inc, dec);
        }
    }

    std::cout << (SM + DP[0][N-1]) / 2 << "\n";
}
