#include <bits/stdc++.h>

std::pair<int, int> dfs1(int v, int p, int d, std::vector<std::vector<int>> &ADJ) {
    std::pair<int, int> res = {d, v};
    for (int u : ADJ[v]) {
        if (u == p) continue;
        std::pair<int, int> tmp = dfs1(u, v, d+1, ADJ);
        res = std::max(res, tmp);
    }
    return res;
}

void dfs2(int v, int p, std::vector<int> &D, std::vector<std::vector<int>> &ADJ) {
    for (int u : ADJ[v]) {
        if (u == p) continue;
        D[u] = D[v] + 1;
        dfs2(u, v, D, ADJ);
    }
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

    std::pair<int, int> E1 = dfs1(0, -1, 0, ADJ);
    std::pair<int, int> E2 = dfs1(E1.second, -1, 0, ADJ);

    std::vector<int> D1(N), D2(N);
    dfs2(E1.second, -1, D1, ADJ);
    dfs2(E2.second, -1, D2, ADJ);

    for (int i = 0; i < N; i++) std::cout << std::max(D1[i], D2[i]) << "\n";
}
