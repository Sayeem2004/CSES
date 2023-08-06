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

    segment_tree<int> ST(N, 0, [](int a, int b) { return a ^ b; });
    for (int i = 0; i < N; i++) {
        int x; std::cin >> x;
        ST.update(i, x);
    }

    for (int i = 0; i < Q; i++) {
        int a, b; std::cin >> a >> b; a--; b--;
        std::cout << ST.query(a, b) << "\n";
    }
}
