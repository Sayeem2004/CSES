#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long N; std::cin >> N;

    for (long long i = 1; i <= N; i++) {
        long long total = (i * i) * (i * i - 1) / 2;
        long long check = (i - 1) * (i - 2) * 2;

        std::cout << total - 2 * check << '\n';
    }
}
