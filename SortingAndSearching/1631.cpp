#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N; std::cin >> N;

    long long sm = 0, mx = 0;
    for (int i = 0; i < N; i++) {
        long long x; std::cin >> x;
        sm += x; mx = std::max(mx, x);
    }

    std::cout << std::max(2 * mx, sm) << "\n";
}
