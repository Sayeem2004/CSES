#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long N; std::cin >> N;
    long long ans = 0, mod = 1e9 + 7;
    long long sq = sqrt(N)+1;

    for (long long i = 1; i < sq; i++) { ans += N / i * i; ans %= mod; }
    for (long long i = 1; i < sq; i++) {
        long long mn = N / (i+1) + 1, mx = N / i;
        if (mn > mx || mn < sq) continue;

        long long fac1 = (mn + mx);
        long long fac2 = (mx - mn + 1);
        if (fac1 % 2 == 0) fac1 /= 2; else fac2 /= 2;

        long long sum = (fac1 % mod) * (fac2 % mod) % mod;
        sum = sum * i % mod;
        ans += sum; ans %= mod;
    }

    std::cout << ans << "\n";
}
