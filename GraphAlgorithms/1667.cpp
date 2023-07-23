#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, M; std::cin >> N >> M;

    std::vector<std::vector<int>> ADJ(N);
    for (int i = 0; i < M; i++) {
        int u, v; std::cin >> u >> v;
        ADJ[u-1].push_back(v-1);
        ADJ[v-1].push_back(u-1);
    }

    std::vector<int> DIST(N, 1e9), PREV(N, -1), VIS(N, 0);
    typedef std::pair<int, int> node;
    std::priority_queue<node, std::vector<node>, std::greater<node>> PQ;
    PQ.push({0, 0});

    while (!PQ.empty()) {
        std::pair<int, int> p = PQ.top(); PQ.pop();
        int v = p.second, d = p.first;

        if (VIS[v]) continue;
        VIS[v] = true;

        for (int u : ADJ[v]) {
            if (VIS[u]) continue;
            if (DIST[u] > d+1) {
                PQ.push({d+1, u});
                DIST[u] = d+1; PREV[u] = v;
            }
        }
    }

    if (DIST[N-1] == 1e9) { std::cout << "IMPOSSIBLE\n"; return 0; }

    std::cout << DIST[N-1] + 1 << "\n";
    std::vector<int> PATH;
    for (int v = N-1; v != -1; v = PREV[v]) PATH.push_back(v+1);

    std::reverse(PATH.begin(), PATH.end());
    for (int v : PATH) std::cout << v << " ";
    std::cout << "\n";
}
