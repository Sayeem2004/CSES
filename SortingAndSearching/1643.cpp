#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N; std::cin >> N;

    long long ans = -1e9, curr = 0;
    for (int i = 0; i < N; i++) {
        long long x; std::cin >> x;

        curr = std::max(x, curr + x);
        ans = std::max(ans, curr);
    }

    std::cout << ans << "\n";
}
