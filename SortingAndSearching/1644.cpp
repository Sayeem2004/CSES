#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long N, A, B; std::cin >> N >> A >> B;

    std::vector<long long> P(N+1, 0);
    for (long long i = 1; i <= N; ++i) {
        std::cin >> P[i]; P[i] += P[i-1];
    }

    long long ans = -1e18;
    std::multiset<long long> MS;
    for (int i = A; i <= N; i++) {
        if (i > B) MS.erase(MS.find(P[i-B-1]));
        MS.insert(P[i-A]);
        ans = std::max(ans, P[i] - *MS.begin());
    }

    std::cout << ans << "\n";
}
