#include <bits/stdc++.h>

std::pair<int, int> dfs(int v, int p, int d, std::vector<std::vector<int>> &ADJ) {
    std::pair<int, int> res = {d, v};
    for (int u : ADJ[v]) {
        if (u == p) continue;
        std::pair<int, int> tmp = dfs(u, v, d+1, ADJ);
        res = std::max(res, tmp);
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N; std::cin >> N;
    std::vector<std::vector<int>> ADJ(N);
    for (int i = 0; i < N-1; i++) {
        int u, v; std::cin >> u >> v;
        ADJ[u-1].push_back(v-1);
        ADJ[v-1].push_back(u-1);
    }

    std::pair<int, int> E1 = dfs(0, -1, 0, ADJ);
    std::pair<int, int> E2 = dfs(E1.second, -1, 0, ADJ);
    std::cout << E2.first << "\n";
}
