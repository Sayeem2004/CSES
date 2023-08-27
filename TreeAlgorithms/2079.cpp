#include <bits/stdc++.h>

void dfs_size(int v, int p, std::vector<std::vector<int>> &ADJ, std::vector<int> &SZ) {
    SZ[v] = 1;
    for (int u : ADJ[v]) {
        if (u == p) continue;
        dfs_size(u, v, ADJ, SZ);
        SZ[v] += SZ[u];
    }
}

int dfs_centroid(int v, int p, int N, std::vector<std::vector<int>> &ADJ, std::vector<int> &SZ) {
    for (int u : ADJ[v]) {
        if (u == p) continue;
        if (SZ[u] * 2 > N) return dfs_centroid(u, v, N, ADJ, SZ);
    }
    return v;
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

    std::vector<int> SZ(N);
    dfs_size(0, -1, ADJ, SZ);
    std::cout << dfs_centroid(0, -1, N, ADJ, SZ) + 1 << "\n";
}
