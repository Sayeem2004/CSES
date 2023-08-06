#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, MX = 0; std::cin >> N;
    std::unordered_map<int, int> M;
    for (int i = 0; i < N; ++i) {
        int x; std::cin >> x;
        M[x]++; MX = std::max(MX, x);
    }

    for (int i = MX; i > 0; i--) {
        int cnt = 0;
        for (int q = i; q <= MX; q += i) cnt += M[q];
        if (cnt >= 2) { std::cout << i << "\n"; return 0; }
    }
}
