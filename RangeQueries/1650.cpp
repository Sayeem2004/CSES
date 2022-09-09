#include <bits/stdc++.h>
using namespace std;

template<class T> struct seg_tree {
    // Variable declarations
    vector<T> SEG; long long N; T DEF = (T) NULL;

    // Combination operation
    T combine(T a, T b) { return a ^ b; }

    // Constructors
    seg_tree(long long n) { N = n; SEG.assign(2 * n, (T) NULL); }
    seg_tree(long long n, T def) { N = n; DEF = def; SEG.assign(2 * n, def); }

    // Mutators
    void pull(long long p) { SEG[p] = combine(SEG[2 * p], SEG[2 * p + 1]); }
    void update(long long p, T val) {
        if (p < 0 || p >= N) return;
        SEG[p += N] = val;
        for (p /= 2; p; p /= 2) pull(p);
    }

    // Accessors
    T get(long long p) { return (p < 0 || p >= N ? (T) NULL : SEG[p + N]); }
    T query(long long l, long long r) { // [l, r]
        if (l < 0 || r < 0 || l >= N || r >= N) return (T) NULL;
        T ra = DEF, rb = DEF;
        for (l += N, r += N+1; l < r; l /= 2, r /= 2) {
            if (l & 1) ra = combine(ra, SEG[l++]);
            if (r & 1) rb = combine(SEG[--r], rb);
        }
        return combine(ra, rb);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long n, q; cin >> n >> q;
    seg_tree<long long> ST(n, 0);
    for (int i = 0; i < n; i++) {
        long long x; cin >> x;
        ST.update(i, x);
    }
    for (int i = 0; i < q; i++) {
        long long l, r; cin >> l >> r;
        cout << ST.query(l-1, r-1) << '\n';
    }
}
