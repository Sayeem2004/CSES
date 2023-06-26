#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long N; std::cin >> N;

    long long ans = 0, curr = 5;
    while (curr <= N) {
        ans += N / curr;
        curr *= 5;
    }

    std::cout << ans << '\n';
}
