#include <bits/stdc++.h>


struct topo_sort {
    std::vector<std::vector<int>> ADJ; std::vector<int> ANS, VIS; int N; // Variables
    topo_sort(int n, std::vector<std::vector<int>> &a) : ADJ(a), N(n) { } // Constructors

    void dfs(int v) { VIS[v] = 1; for (int u : ADJ[v]) if (!VIS[u]) dfs(u); ANS.push_back(v); }
    std::vector<int> sort() { ANS.clear(); VIS.assign(N, 0); for (int i = 0; i < N; i++)
        if (!VIS[i]) dfs(i); std::reverse(ANS.begin(), ANS.end()); return ANS; }
    bool check() { std::map<int, int> MP; for (int i = 0; i < N; i++) MP[ANS[i]] = i;
        for (int i = 0; i < N; i++) for (int q = 0; q < ADJ[i].size(); q++)
            if (MP[i] > MP[ADJ[i][q]]) return false; return true; } // Accessors
};

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, M; std::cin >> N >> M;
    std::vector<std::vector<int>> ADJ(N);
    for (int i = 0; i < M; i++) {
        int u, v; std::cin >> u >> v;
        ADJ[u-1].push_back(v-1);
    }

    topo_sort TS(N, ADJ);
    std::vector<int> ANS = TS.sort();

    if (!TS.check()) { std::cout << "IMPOSSIBLE\n"; return 0; }
    for (int i = 0; i < N; i++) std::cout << ANS[i]+1 << " ";
    std::cout << "\n";
}
