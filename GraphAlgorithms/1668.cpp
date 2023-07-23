#include <bits/stdc++.h>

bool dfs(int v, int c, std::vector<int>& COLOR, const std::vector<std::vector<int>>& ADJ) {
    if (COLOR[v] != -1) return COLOR[v] == c;
    COLOR[v] = c;

    bool res = true;
    for (int u : ADJ[v]) { res &= dfs(u, 1-c, COLOR, ADJ); }
    return res;
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, M; std::cin >> N >> M;

    std::vector<std::vector<int>> ADJ(N);
    for (int i = 0; i < M; ++i) {
        int u, v; std::cin >> u >> v;
        ADJ[u-1].push_back(v-1);
        ADJ[v-1].push_back(u-1);
    }

    std::vector<int> COLOR(N, -1);
    bool res = true;
    for (int i = 0; i < N; ++i) {
        if (COLOR[i] == -1) { res &= dfs(i, 0, COLOR, ADJ); }
    }

    if (!res) { std::cout << "IMPOSSIBLE\n"; }
    for (int v : COLOR) { std::cout << v+1 << ' '; }
    std::cout << '\n';
}
