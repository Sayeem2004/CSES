#include <bits/stdc++.h>

void factor(int n, std::unordered_map<int, int> &M) {
    while (n % 2 == 0) { M[2]++; n /= 2; }
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) { M[i]++; n /= i; }
    }
    if (n > 1) M[n]++;
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int T; std::cin >> T; while (T--) {
        int N; std::cin >> N;
        std::unordered_map<int, int> M;
        factor(N, M);

        long long ans = 1;
        for (auto &p : M) ans *= (p.second + 1);
        std::cout << ans << "\n";
    }
}
