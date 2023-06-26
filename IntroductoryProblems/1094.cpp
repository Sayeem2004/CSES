#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N; std::cin >> N;

    std::vector<long long> V(N);
    for (long long &v : V) std::cin >> v;

    long long ans = 0;
    for (int i = 1; i < (int) V.size(); i++) {
        ans += std::max(0LL, V[i-1] - V[i]);
        V[i] = std::max(V[i], V[i-1]);
    }

    std::cout << ans << '\n';
}
