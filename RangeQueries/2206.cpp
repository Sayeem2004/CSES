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
    struct node { int cost, pen; };

    segment_tree<node> DST(N, node{1000000000, 0}, [](node a, node b) {
        if (a.cost - a.pen < b.cost - b.pen) return a;
        else return b;
    });

    segment_tree<node> UST(N, node{1000000000, 1000000000}, [](node a, node b) {
        if (a.cost + a.pen < b.cost + b.pen) return a;
        else return b;
    });

    for (int i = 0; i < N; i++) {
        int x; std::cin >> x;
        DST.update(i, {x, i});
        UST.update(i, {x, i});
    }

    for (int i = 0; i < Q; i++) {
        int t; std::cin >> t;

        if (t == 1) {
            int a, b; std::cin >> a >> b; a--;
            DST.update(a, {b, a});
            UST.update(a, {b, a});
        } else {
            int x; std::cin >> x; x--;
            node d = DST.query(0, x), u = UST.query(x, N - 1);
            std::cout << std::min(d.cost-d.pen+x, u.cost+u.pen-x) << "\n";
        }
    }
}
