#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long N; std::cin >> N;

    while (N > 1) {
        std::cout << N << ' ';

        if (N % 2 == 0) N /= 2;
        else N = N * 3 + 1;
    }

    std::cout << 1 << '\n';
}
