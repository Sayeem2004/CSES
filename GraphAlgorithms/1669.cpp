#include <bits/stdc++.h>

bool dfs(int v, int p, int &s, int &e, std::vector<std::vector<int>> &ADJ,
    std::vector<bool> &VIS, std::vector<int> &PREV) {

    VIS[v] = true;
    PREV[v] = p;

    for (int u : ADJ[v]) {
        if (u == p) continue;
        if (VIS[u]) { s = u; e = v; return true; }
        if (dfs(u, v, s, e, ADJ, VIS, PREV)) return true;
    }

    return false;
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

    std::vector<bool> VIS(N, false);
    std::vector<int> PREV(N, -1);
    int s = -1, e = -1;
    for (int i = 0; i < N; ++i) {
        if (VIS[i]) continue;
        if (dfs(i, -1, s, e, ADJ, VIS, PREV)) break;
    }

    if (s == -1 || e == -1) { std::cout << "IMPOSSIBLE\n"; return 0; }

    std::vector<int> PATH;
    for (int v = e; v != s; v = PREV[v]) PATH.push_back(v);
    PATH.push_back(s);

    std::cout << PATH.size()+1 << "\n";
    for (int v : PATH) std::cout << v+1 << " ";
    std::cout << e+1 << "\n";
}
