#include <bits/stdc++.h>

template<typename T> struct segment_lca { // Variables & Constructors
    std::vector<std::vector<T>> ADJ; std::vector<T> HGT, FST, VIS, EUL, SEG; T N, P, R;
    segment_lca(T n, std::vector<std::vector<T>> &adj, T r = 0) : ADJ(adj), N(n), P(0) {
        HGT.resize(N); FST.resize(N); VIS.resize(N); EUL.resize(2*N); dfs(r, 0);
        SEG.resize(4*N); for (T i = 0; i < 2*N; i++) update(i, EUL[i]); }

    void pull(T p) { SEG[p] = comb(SEG[2*p], SEG[2*p+1]); } // Mutators
    void update(T p, T v) { SEG[p += 2*N] = v; for (p /= 2; p; p /= 2) pull(p); }
    void dfs(T v, T h) { VIS[v] = 1; HGT[v] = h; FST[v] = P; EUL[P++] = v;
        for (T u : ADJ[v]) if (!VIS[u]) { dfs(u, h+1); EUL[P++] = v; } }

    T comb(T a, T b) { return HGT[a] < HGT[b] ? a : b; } // Helpers & Accessors
    T dist(T a, T b) { return HGT[a] + HGT[b] - 2*HGT[find(a, b)]; }
    T find(T a, T b) { if (FST[a] > FST[b]) std::swap(a, b); return query(FST[a], FST[b]); }
    T query(T l, T r) { T ra = SEG[l += 2*N], rb = SEG[r += 2*N]; for (r++; l < r; l /= 2, r /= 2)
        { if (l & 1) ra = comb(ra, SEG[l++]); if (r & 1) rb = comb(SEG[--r], rb); } return comb(ra, rb); }
};

void dfs(int v, int p, std::vector<std::vector<int>> &ADJ, std::vector<int> &DP) {
    for (int u : ADJ[v]) { if (u != p) { dfs(u, v, ADJ, DP); DP[v] += DP[u]; } }
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, M; std::cin >> N >> M;
    std::vector<std::vector<int>> ADJ(N);
    for (int i = 0; i < N-1; i++) {
        int u, v; std::cin >> u >> v; u--; v--;
        ADJ[u].push_back(v); ADJ[v].push_back(u);
    }

    segment_lca<int> LCA(N, ADJ);
    std::vector<int> DP(N);
    for (int i = 0; i < M; i++) {
        int u, v; std::cin >> u >> v; u--; v--;
        int lca = LCA.find(u, v);
        DP[u]++; DP[v]++; DP[lca]--;
        if (LCA.PAR[lca] != -1) DP[LCA.PAR[lca]]--;
    }

    dfs(0, -1, ADJ, DP);
    for (int i = 0; i < N; i++) std::cout << DP[i] << " ";
    std::cout << "\n";
}
