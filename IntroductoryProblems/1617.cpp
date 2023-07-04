#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long N; std::cin >> N;

    long long ans = 1, mod = 1e9 + 7;
    for (long long i = 1; i <= N; i++) ans = (ans * 2) % mod;

    std::cout << ans << "\n";
}
