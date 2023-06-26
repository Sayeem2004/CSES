#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N; std::cin >> N;

    if (N == 1) {
        std::cout << "1\n";
        return 0;
    }

    if (N < 4) {
        std::cout << "NO SOLUTION\n";
        return 0;
    }

    for (int i = 2; i <= N; i += 2) std::cout << i << ' ';
    for (int i = 1; i <= N; i += 2) std::cout << i << ' ';
    std::cout << '\n';
}
