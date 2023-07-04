#include <bits/stdc++.h>

bool check(long long x, long long n) {
    for (long long i = 1; i <= std::min(x, n); i <<= 1) {
        int dx = (x & i) > 0, dn = (n & i) > 0;
        if (dx && !dn) return false;
    }
    return true;
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long N; std::cin >> N;

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        long long x; std::cin >> x;
        if (check(i, N-1)) ans ^= x;
    }

    std::cout << ans << "\n";
}
