#include <bits/stdc++.h>

template<typename T> struct topo_sort {
    std::vector<std::vector<T>> ADJ; std::vector<T> ANS, VIS; T N; // Variables
    topo_sort(T n, std::vector<std::vector<T>> &adj) : ADJ(adj), N(n) { } // Constructors

    void dfs(T v) { VIS[v] = 1; for (T u : ADJ[v]) if (!VIS[u]) { dfs(u); } ANS.push_back(v); } // Accessors
    std::vector<T> sort() { ANS.clear(); VIS.assign(N, 0); for (T i = 0; i < N; i++) {
        if (!VIS[i]) { dfs(i); } } std::reverse(ANS.begin(), ANS.end()); return ANS; }
    bool check() { std::map<T, T> MP; for (T i = 0; i < N; i++) MP[ANS[i]] = i; for (T i = 0; i < N; i++) {
        for (T q = 0; q < ADJ[i].size(); q++) if (MP[i] > MP[ADJ[i][q]]) return false; } return true; }
};

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, M; std::cin >> N >> M;
    const int MAXN = 50000;

    std::vector<std::vector<int>> ADJ(N);
    for (int i = 0; i < M; i++) {
        int u, v; std::cin >> u >> v;
        ADJ[u-1].push_back(v-1);
    }

    topo_sort<int> TS(N, ADJ);
    std::vector<int> SRT = TS.sort();
    std::vector<std::bitset<MAXN>> MAT(N);

    for (int i = N-1; i >= 0; i--) {
        MAT[SRT[i]][SRT[i]] = 1;
        for (int u : ADJ[SRT[i]]) MAT[SRT[i]] |= MAT[u];
    }

    for (int i = 0; i < N; i++) std::cout << MAT[i].count() << " ";
    std::cout << "\n";
}
