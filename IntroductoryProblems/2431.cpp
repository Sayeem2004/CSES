#include <bits/stdc++.h>

long long count(long long n) {
    long long cnt = 0;

    for (long long i = 10, q = 1; ; i *= 10, q++) {
        if (i > n) { cnt += (n - i / 10 + 1) * q; break; }
        cnt += (i - i / 10) * q;
    }

    return cnt;
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int T; std::cin >> T; while (T--) {
        long long K; std::cin >> K;

        long long val = 0;
        for (long long i = 1e18; i >= 1; i /= 2) {
            while (count(val + i) < K) val += i;
        }

        std::string num = std::to_string(val + 1);
        long long cnt = count(val + 1) - K;

        std::cout << num[num.size() - cnt - 1] << '\n';
    }
}
