#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long N, X; std::cin >> N >> X;
    std::vector<long long> V(N);
    for (long long &v : V) std::cin >> v;

    std::vector<std::pair<long long, long long>> DP(1 << N, {1e9, 1e9});
    DP[0] = {1, 0};

    for (int i = 1; i < 1 << N; i++) {
        for (int q = 0; q < N; q++) {
            if (i && (1 << q)) {
                std::pair<long long, long long> prev = DP[i ^ (1 << q)];

                if (prev.second + V[q] <= X) prev.second += V[q];
                else { prev.first++; prev.second = V[q]; }

                DP[i] = std::min(DP[i], prev);
            }
        }
    }

    std::cout << DP[(1 << N) - 1].first << "\n";
}
