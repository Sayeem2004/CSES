#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N; std::cin >> N;
    const int MOD = 1e9 + 7;

    std::vector<int> DP(N + 1, 0);
    DP[0] = 1;

    for (int i = 1; i <= N; i++) {
        if (i >= 1) { DP[i] += DP[i-1]; DP[i] %= MOD; }
        if (i >= 2) { DP[i] += DP[i-2]; DP[i] %= MOD; }
        if (i >= 3) { DP[i] += DP[i-3]; DP[i] %= MOD; }
        if (i >= 4) { DP[i] += DP[i-4]; DP[i] %= MOD; }
        if (i >= 5) { DP[i] += DP[i-5]; DP[i] %= MOD; }
        if (i >= 6) { DP[i] += DP[i-6]; DP[i] %= MOD; }
    }

    std::cout << DP[N] << "\n";
}
