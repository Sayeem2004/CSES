#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N; std::cin >> N;

    int SM = 0;
    std::vector<int> V(N);
    for (int &v : V) {
        std::cin >> v;
        SM += v;
    }

    std::vector<std::vector<bool>> DP(N+1, std::vector<bool>(SM+1, false));
    for (int i = 0; i <= N; i++) DP[i][0] = true;

    for (int i = 1; i <= N; i++) {
        for (int q = 1; q <= SM; q++) {
            DP[i][q] = DP[i-1][q] || (q >= V[i-1] ? DP[i-1][q-V[i-1]] : false);
        }
    }

    int ans = 0;
    std::vector<bool> ANS(SM+1, false);
    for (int i = 1; i <= SM; i++) {
        if (DP[N][i]) { ANS[i] = true; ans++; }
    }

    std::cout << ans << "\n";
    for (int i = 1; i <= SM; i++) {
        if (ANS[i]) std::cout << i << " ";
    }
    std::cout << "\n";
}
