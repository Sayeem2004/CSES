#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long N, X; std::cin >> N >> X;
    std::map<long long, long long> M;
    long long ans = 0, sum = 0;
    M[0] = 1;

    for (long long i = 0; i < N; ++i) {
        long long a; std::cin >> a;
        sum += a; ans += M[sum - X];
        M[sum]++;
    }

    std::cout << ans << "\n";
}
