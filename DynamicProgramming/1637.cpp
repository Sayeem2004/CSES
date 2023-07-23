#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N; std::cin >> N;

    std::vector<int> DP(N + 1, 1e9);
    DP[0] = 0;

    for (int i = 1; i <= N; i++) {
        int cpy = i;
        while (cpy) { DP[i] = std::min(DP[i], DP[i-cpy%10] + 1); cpy /= 10; }
    }

    std::cout << DP[N] << "\n";
}
