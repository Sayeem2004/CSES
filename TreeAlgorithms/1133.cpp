#include <bits/stdc++.h>

long long dfs1(int v, int p, int d, std::vector<std::vector<int>> &ADJ) {
    long long ans = d;
    for (int u : ADJ[v]) {
        if (u == p) continue;
        ans += dfs1(u, v, d+1, ADJ);
    }
    return ans;
}

void dfs2(int v, int p, std::vector<long long> &C, std::vector<std::vector<int>> &ADJ) {
    C[v] = 1;
    for (int u : ADJ[v]) {
        if (u == p) continue;
        dfs2(u, v, C, ADJ);
        C[v] += C[u];
    }
}

void dfs3(int v, int p, int n, std::vector<long long> &D, std::vector<long long> &C, std::vector<std::vector<int>> &ADJ) {
    for (int u : ADJ[v]) {
        if (u == p) continue;
        D[u] = D[v] + n - 2*C[u];
        dfs3(u, v, n, D, C, ADJ);
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

    std::vector<long long> C(N), D(N);
    D[0] = dfs1(0, -1, 0, ADJ);
    dfs2(0, -1, C, ADJ);
    dfs3(0, -1, N, D, C, ADJ);

    for (int i = 0; i < N; i++) std::cout << D[i] << " ";
    std::cout << "\n";
}
