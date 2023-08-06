#include <bits/stdc++.h>

template<typename T> struct segment_tree {
    std::vector<T> SEG; int N; T DEF; T (*OP)(T, T); // Variables
    segment_tree(int n, T d = NULL, T (*c)(T, T) = [](T a, T b) { return a+b; })
        : N(n), DEF(d), OP(c) { SEG.assign(2*N, DEF); } // Constructors

    void pull(int p) { SEG[p] = OP(SEG[2*p], SEG[2*p+1]); } // Mutators
    void update(int p, T v) { if (p < 0 || p >= N) return;
        SEG[p += N] = v; for (p /= 2; p; p /= 2) pull(p); }

    T get(int p) { return (p < 0 || p >= N ? DEF : SEG[p+N]); } // Accessors
    void print() { for (T elem : SEG) std::cout << elem << " "; std::cout << "\n"; }
    T query(int l, int r) { T ra = DEF, rb = DEF; // [l, r]
        if (l < 0 || r < 0 || l >= N || r >= N || l > r) return DEF;
        for (l += N, r += N+1; l < r; l /= 2, r /= 2) { if (l & 1) ra = OP(ra, SEG[l++]);
        if (r & 1) rb = OP(SEG[--r], rb); } return OP(ra, rb); }
};

void dfs(int v, int p, int &cnt, std::map<int, int> &LFT, std::map<int, int> &RGT, std::vector<std::vector<int>>& ADJ) {
    LFT[v] = cnt++;
    for (int u : ADJ[v]) {
        if (u == p) continue;
        dfs(u, v, cnt, LFT, RGT, ADJ);
    }
    RGT[v] = cnt-1;
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, Q; std::cin >> N >> Q;
    std::vector<long long> V(N);
    for (long long &v : V) std::cin >> v;

    std::vector<std::vector<int>> ADJ(N);
    for (int i = 0; i < N-1; i++) {
        int a, b; std::cin >> a >> b;
        ADJ[a-1].push_back(b-1);
        ADJ[b-1].push_back(a-1);
    }

    std::map<int, int> LFT, RGT; int cnt = 0;
    dfs(0, -1, cnt, LFT, RGT, ADJ);
    segment_tree<long long> ST(N, 0);
    for (int i = 0; i < N; i++) ST.update(LFT[i], V[i]);

    for (int i = 0; i < Q; i++) {
        int t, s, x; std::cin >> t;
        if (t == 1) { std::cin >> s >> x; ST.update(LFT[s-1], x); }
        else { std::cin >> s; std::cout << ST.query(LFT[s-1], RGT[s-1]) << "\n"; }
    }
}
