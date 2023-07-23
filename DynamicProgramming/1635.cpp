#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, X; std::cin >> N >> X;
    const int MOD = 1e9 + 7;

    std::vector<int> V(N);
    for (int& v : V) std::cin >> v;
    std::sort(V.begin(), V.end());

    std::vector<int> DP(X + 1, 0);
    DP[0] = 1;

    for (int i = 1; i <= X; i++) {
        for (int q = 0; q < N; q++) {
            if (V[q] > i) break;
            DP[i] += DP[i-V[q]];
            DP[i] %= MOD;
        }
    }

    std::cout << DP[X] << "\n";
}
