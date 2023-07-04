#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long N; std::cin >> N;

    long long sm = 0;
    for (int i = 0; i < N-1; i++) {
        int x; std::cin >> x;
        sm += x;
    }

    std::cout << N * (N+1) / 2 - sm << "\n";
}
