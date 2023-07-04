#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, K; std::cin >> N >> K;

    std::vector<int> V(N);
    for (int &v : V) {
        std::string s; std::cin >> s;
        v = std::stoi(s, nullptr, 2);
    }

    int ans = 30;
    for (int i = 0; i < N; i++) {
        for (int q = i+1; q < N; q++) {
            ans = std::min(ans, __builtin_popcount(V[i]^V[q]));
        }
    }

    std::cout << ans << "\n";
}
