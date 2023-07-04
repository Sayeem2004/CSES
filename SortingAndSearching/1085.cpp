#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long N, K; std::cin >> N >> K;
    std::vector<long long> V(N);
    for (long long& v : V) std::cin >> v;

    long long l = 0, r = 1e18;
    while (l < r) {
        long long m = (l + r) / 2;

        long long curr = 0, cnt = 1;
        for (int i = 0; i < N; i++) {
            if (curr + V[i] > m) { curr = 0; cnt++; }
            curr += V[i];

            if (V[i] > m) { cnt = K + 1; break; }
        }

        if (cnt <= K) r = m;
        else l = m + 1;
    }

    std::cout << (l + r) / 2 << "\n";
}
