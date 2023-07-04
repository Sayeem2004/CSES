#include <bits/stdc++.h>

void solve(int n, int s, int e) {
    if (n == 0) return;

    solve(n - 1, s, 6 - s - e);
    std::cout << s << " " << e << "\n";
    solve(n - 1, 6 - s - e, e);
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N; std::cin >> N;

    std::cout << (1 << N) - 1 << "\n";
    solve(N, 1, 3);
}
