#include <bits/stdc++.h>

void dfs(int v, int p, const std::vector<std::vector<int>> &ADJ, std::vector<int> &DP1, std::vector<int> &DP2) {
    for (int u : ADJ[v]) {
        if (u == p) continue;
        dfs(u, v, ADJ, DP1, DP2);
        DP1[v] += std::max(DP1[u], DP2[u]);
    }
    for (int u : ADJ[v]) {
        if (u == p) continue;
        DP2[v] = std::max(DP2[v], (DP1[v] - std::max(DP1[u], DP2[u])) + DP1[u] + 1);
    }
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N; std::cin >> N;
    std::vector<std::vector<int>> ADJ(N);
    for (int i = 0; i < N-1; i++) {
        int a, b; std::cin >> a >> b;
        ADJ[a-1].push_back(b-1);
        ADJ[b-1].push_back(a-1);
    }

    std::vector<int> DP1(N), DP2(N);
    dfs(0, -1, ADJ, DP1, DP2);
    std::cout << std::max(DP1[0], DP2[0]) << "\n";
}
