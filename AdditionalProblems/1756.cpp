#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, M; std::cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b; std::cin >> a >> b;
        if (a < b) std::swap(a, b);

        std::cout << a << " " << b << "\n";
    }
}
