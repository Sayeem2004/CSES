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

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, Q; std::cin >> N >> Q;

    std::vector<long long> V(N);
    for (long long &v : V) std::cin >> v;

    segment_tree<long long> ST(N, 0);

    for (int i = 0; i < Q; i++) {
        int t; std::cin >> t;

        if (t == 1) {
            int a, b, c; std::cin >> a >> b >> c;
            ST.update(a - 1, ST.get(a - 1) + c);
            ST.update(b, ST.get(b) - c);
        } else {
            int a; std::cin >> a;
            std::cout << V[a - 1] + ST.query(0, a - 1) << "\n";
        }
    }
}
