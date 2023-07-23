#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long N, M, Q; std::cin >> N >> M >> Q;
    std::vector<std::vector<long long>> ADJ(N, std::vector<long long>(N, 1e18));
    std::vector<std::vector<long long>> DIST(N, std::vector<long long>(N, 1e18));

    for (long long i = 0; i < M; ++i) {
        long long u, v, w; std::cin >> u >> v >> w;
        ADJ[u-1][v-1] = std::min(ADJ[u-1][v-1], w);
        ADJ[v-1][u-1] = std::min(ADJ[v-1][u-1], w);
        DIST[u-1][v-1] = std::min(DIST[u-1][v-1], w);
        DIST[v-1][u-1] = std::min(DIST[v-1][u-1], w);
    }
    for (long long i = 0; i < N; ++i) DIST[i][i] = 0;

    for (long long i = 0; i < N; i++) {
        for (long long q = 0; q < N; q++) {
            for (long long r = 0; r < N; r++) {
                DIST[q][r] = std::min(DIST[q][r], DIST[q][i] + DIST[i][r]);
            }
        }
    }

    for (long long i = 0; i < Q; ++i) {
        long long u, v; std::cin >> u >> v;
        std::cout << (DIST[u-1][v-1] == 1e18 ? -1 : DIST[u-1][v-1]) << "\n";
    }
}
