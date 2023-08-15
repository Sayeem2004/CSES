#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long X, N; std::cin >> X >> N;

    std::multiset<long long> MS;
    for (int i = 0; i < N; i++) {
        long long x; std::cin >> x;
        MS.insert(x);
    }

    long long ans = 0;
    while (MS.size() > 1) {
        long long a = *MS.begin(); MS.erase(MS.begin());
        long long b = *MS.begin(); MS.erase(MS.begin());
        ans += a + b;
        MS.insert(a + b);
    }

    std::cout << ans << "\n";
}
