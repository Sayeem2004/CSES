#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N; std::cin >> N;

    if (N % 4 == 1 || N % 4 == 2) std::cout << "NO\n";
    else std::cout << "YES\n";

    if (N % 4 == 0) {
        std::cout << N / 2 << "\n";
        for (int i = 1; i <= N; i += 4) std::cout << i << " " << i + 3 << " ";
        std::cout << "\n";

        std::cout << N / 2 << "\n";
        for (int i = 2; i <= N; i += 4) std::cout << i << " " << i + 1 << " ";
        std::cout << "\n";
    } else if (N % 4 == 3) {
        std::cout << N / 2 + 1 << "\n";
        std::cout << 1 << " " << 2 << " ";
        for (int i = 5; i <= N; i += 4) std::cout << i << " " << i + 1 << " ";
        std::cout << "\n";

        std::cout << N / 2 << "\n";
        std::cout << 3 << " ";
        for (int i = 4; i <= N; i += 4) std::cout << i << " " << i + 3 << " ";
        std::cout << "\n";
    }
}
