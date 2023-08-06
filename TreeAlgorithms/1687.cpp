#include <bits/stdc++.h>

template<typename T> struct binary_lift { // Variables & Constructors
    std::vector<std::vector<T>> ADJ, UP; std::vector<T> IN, OUT; T N, L, C;
    binary_lift(T n, std::vector<std::vector<T>> &adj, T r = 0) : ADJ(adj), N(n), L(log2(N)), C(0) {
        IN.resize(N); OUT.resize(N); UP.resize(N, std::vector<T>(L+1, -1)); dfs(r, -1); }
    void dfs(T v, T p) { IN[v] = C++; UP[v][0] = p; for (T i = 1; i <= L; i++) { if (UP[v][i-1] != -1)
        UP[v][i] = UP[UP[v][i-1]][i-1]; } for (T u : ADJ[v]) { if (u != p) dfs(u, v); } OUT[v] = C++; }

    T log2(T n) { return 31 - __builtin_clz(n); } // Helpers & Accessors
    bool anc(T v, T u) { return IN[v] <= IN[u] && OUT[v] >= OUT[u]; }
    T jump(T v, T k) { for (T i = 0; i <= L; i++) { if (k & (1 << i)) { if ((v = UP[v][i]) == -1) break; } } return v; }
    T lca(T v, T u) { if (anc(v, u)) return v; if (anc(u, v)) return u; for (T i = L; i >= 0; i--)
        { if (!anc(UP[v][i], u)) v = UP[v][i]; } return UP[v][0]; }
};

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, Q; std::cin >> N >> Q;
    std::vector<std::vector<int>> ADJ(N);
    for (int i = 1; i < N; i++) {
        int x; std::cin >> x;
        ADJ[x-1].push_back(i);
        ADJ[i].push_back(x-1);
    }

    binary_lift<int> BL(N, ADJ);
    for (int i = 0; i < Q; i++) {
        int v, k; std::cin >> v >> k;
        int b = BL.jump(v-1, k);
        std::cout << (b == -1 ? -1 : b+1) << "\n";
    }
}
