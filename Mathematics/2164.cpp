#include <bits/stdc++.h>

int solve(int n, int k) {
    if (2*k <= n) return 2*k;
    if (2*k == n+1) return 1;

    int prev = solve(n/2, k-(n+1)/2);
    if (n%2 == 0) return 2*prev-1;
    return 2*prev+1;
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int T; std::cin >> T; while (T--) {
        int N, K; std::cin >> N >> K;
        std::cout << solve(N, K) << "\n";
    }
}
