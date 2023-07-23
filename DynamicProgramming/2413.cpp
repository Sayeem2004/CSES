#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long N; std::cin >> N;
    long long M = 0, MOD = 1e9 + 7;

    std::vector<long long> V(N);
    for (long long &v : V) {
        std::cin >> v;
        M = std::max(M, v);
    }

    std::vector<std::array<long long, 2>> DP(M+1);
    DP[1][0] = DP[1][1] = 1; // 0 - cut, 1 - uncut

    for (int i = 2; i <= M; i++) {
        DP[i][0] = (4 * DP[i-1][0] + DP[i-1][1]) % MOD;
        DP[i][1] = (DP[i-1][0] + 2 * DP[i-1][1]) % MOD;
    }

    for (int i = 0; i < N; i++) {
        std::cout << (DP[V[i]][0] + DP[V[i]][1]) % MOD << "\n";
    }
}
