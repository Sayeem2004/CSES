#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N; std::cin >> N;

    for (int i = 0; i < (1 << N); i++) {
        std::string code(N, '0');

        for (int q = 1; q <= N; q++) {
            int mod = 1 << (q + 1);
            int div = 1 << (q - 1);

            if (i % mod >= div && i % mod < mod - div) code[N-q] = '1';
        }

        std::cout << code << '\n';
    }
}
