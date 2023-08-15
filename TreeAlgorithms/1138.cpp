#include <bits/stdc++.h>

template<typename T> struct heavy_decomp { // Variables & Constructors
    std::vector<std::vector<T>> ADJ; std::vector<T> PAR, DEP, HVY, POS, VAL, SEG, HD; T N, P; T (*OP)(T, T);
    heavy_decomp(T n, std::vector<std::vector<T>> &adj, std::vector<T> &val, T (*op)(T, T), T r = 0) {
        N = n; P = 0; ADJ = adj; VAL = val; OP = op; PAR.resize(N); DEP.resize(N); HVY.assign(N, -1); POS.resize(N);
        HD.resize(N); dfs(r); decomp(r, r); SEG.resize(2*N); for (T i = 0; i < N; i++) update(POS[i], VAL[i]); }

    void pull(T p) { SEG[p] = OP(SEG[2*p], SEG[2*p+1]); } // Mutators
    void update(T p, T v) { SEG[p += N] = v; for (p /= 2; p; p /= 2) pull(p); }
    int dfs(T v) { T sz = 1, mx = 0; for (T u : ADJ[v]) if (u != PAR[v]) { PAR[u] = v; DEP[u] = DEP[v] + 1;
        T usz = dfs(u); sz += usz; if (usz > mx) { mx = usz; HVY[v] = u; } } return sz; }
    void decomp(T v, T h) { POS[v] = P++; HD[v] = h; if (HVY[v] != -1) decomp(HVY[v], h);
        for (T u : ADJ[v]) if (u != PAR[v] && u != HVY[v]) decomp(u, u); }

    T query(T l, T r, T d = 0) { T ra = d, rb = d; for (l += N, r += N+1; l < r; l /= 2, r /= 2) { // Accessors
        if (l & 1) ra = OP(ra, SEG[l++]); if (r & 1) rb = OP(SEG[--r], rb); } return OP(ra, rb); }
    T calc(T a, T b, T d = 0) { T res = d; for (; HD[a] != HD[b]; b = PAR[HD[b]]) {
        if (DEP[HD[a]] > DEP[HD[b]]) std::swap(a, b); res = OP(res, query(POS[HD[b]], POS[b], d)); }
        if (DEP[a] > DEP[b]) std::swap(a, b); return OP(res, query(POS[a], POS[b], d)); }
};

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long N, Q; std::cin >> N >> Q;
    std::vector<long long> VAL(N);
    std::vector<std::vector<long long>> ADJ(N);

    for (long long &v : VAL) std::cin >> v;
    for (int i = 0; i < N-1; i++) {
        long long u, v; std::cin >> u >> v;
        ADJ[u-1].push_back(v-1);
        ADJ[v-1].push_back(u-1);
    }

    heavy_decomp<long long> HLD(N, ADJ, VAL, [](long long a, long long b) { return a + b; });
    for (int i = 0; i < Q; i++) {
        int t; std::cin >> t;
        if (t == 1) { long long s, x; std::cin >> s >> x; HLD.update(HLD.POS[s-1], x); }
        else { long long s; std::cin >> s; std::cout << HLD.calc(0, s-1) << "\n"; }
    }
}
