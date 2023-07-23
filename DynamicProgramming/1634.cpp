#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, X; std::cin >> N >> X;

    std::vector<int> V(N);
    for (int &v : V) std::cin >> v;

    std::vector<int> DP(X + 1, 1e9);
    DP[0] = 0;

    for (int i = 1; i <= X; i++) {
        for (int q = 0; q < N; q++) {
            if (i >= V[q]) { DP[i] = std::min(DP[i-V[q]] + 1, DP[i]); }
        }
    }

    std::cout << (DP[X] == 1e9 ? -1 : DP[X]) << "\n";
}
