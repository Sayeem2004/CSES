#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long N; std::cin >> N;

    long long l = 0, r = 1e18;
    while (l < r) {
        long long m = (l + r) / 2, sm = 0;
        for (long long i = 1; i <= N; ++i) sm += std::min(N, m / i);

        if (sm >= (N * N + 1) / 2) r = m;
        else l = m + 1;
    }

    std::cout << (l + r) / 2 << "\n";
}
