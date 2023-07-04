#include <bits/stdc++.h>

template<class T> struct segment_tree {
    std::vector<T> SEG; int N; T DEF; T (*OP)(T, T);

    segment_tree(int n, T d = (T) NULL, T (*c)(T, T) = [](T a, T b) { return a + b; })
        { N = n; DEF = d; OP = c; SEG.assign(2 * N, DEF); } // Constructor

    void pull(int p) { SEG[p] = OP(SEG[2 * p], SEG[2 * p + 1]); } // Mutators
    void update(int p, T v) { if (p < 0 || p >= N) return;
        SEG[p += N] = v; for (p /= 2; p; p /= 2) pull(p); }

    T get(int p) { return (p < 0 || p >= N ? DEF : SEG[p + N]); } // Accessors
    void print() { for (T elem : SEG) std::cout << elem << " "; std::cout << "\n"; }
    T query(int l, int r) { T ra = DEF, rb = DEF; // [l, r]
        if (l < 0 || r < 0 || l >= N || r >= N || l > r) return DEF;
        for (l += N, r += N + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) ra = OP(ra, SEG[l++]);
            if (r & 1) rb = OP(SEG[--r], rb);
        } return OP(ra, rb); }
};

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, Q; std::cin >> N >> Q;

    struct node { long long pref, suff, sum, ans; };
    segment_tree<node> ST(N, {0, 0, 0, 0}, [](node a, node b) {
        return node {
            std::max(a.pref, a.sum + b.pref),
            std::max(b.suff, b.sum + a.suff),
            a.sum + b.sum,
            std::max({a.ans, b.ans, a.suff + b.pref})
        };
    });

    for (int i = 0; i < N; i++) {
        int x; std::cin >> x;
        int m = std::max(x, 0);
        ST.update(i, {m, m, x, m});
    }

    for (int i = 0; i < Q; i++) {
        int a, b; std::cin >> a >> b; a--;
        int m = std::max(b, 0);

        ST.update(a, {m, m, b, m});
        std::cout << ST.query(0, N - 1).ans << "\n";
    }
}
