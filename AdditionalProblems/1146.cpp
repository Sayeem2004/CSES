#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long N; std::cin >> N;
    long long ans = 0;

    for (long long i = 1; i <= 50; i++) {
        long long div = 1LL << i;
        long long cnt = (N + 1) / div * div / 2;
        long long rem = std::max(0LL, (N + 1) % div - div / 2);
        ans += cnt + rem;
    }

    std::cout << ans << "\n";
}
