#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long N, M; std::cin >> N >> M;
    typedef std::pair<long long, long long> node;

    std::vector<std::vector<node>> ADJ(N);
    for (int i = 0; i < M; i++) {
        long long u, v, w; std::cin >> u >> v >> w;
        ADJ[u-1].push_back({v-1, w});
    }

    std::vector<long long> DIST(N, 1e18);
    std::vector<bool> VIS(N, false);
    std::priority_queue<node, std::vector<node>, std::greater<node>> PQ;
    PQ.push({0, 0}); DIST[0] = 0;

    while (!PQ.empty()) {
        node curr = PQ.top(); PQ.pop();
        if (VIS[curr.second]) continue;
        VIS[curr.second] = true;

        for (node next : ADJ[curr.second]) {
            if (DIST[next.first] > DIST[curr.second] + next.second) {
                DIST[next.first] = DIST[curr.second] + next.second;
                PQ.push({DIST[next.first], next.first});
            }
        }
    }

    for (int i = 0; i < N; i++) std::cout << DIST[i] << " ";
    std::cout << "\n";
}
