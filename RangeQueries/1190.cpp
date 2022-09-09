#include <bits/stdc++.h>
using namespace std;

template<class T> struct seg_tree {
    // Variable declarations
    vector<T> SEG; int N; T DEF = {0, 0, 0, 0};

    // Combination operation
    T combine(T a, T b) {
        return {
            max(a[0], a[3]+b[0]), // max prefix
            max({a[1], b[1], a[2]+b[0]}), // max subarray
            max(b[2], b[3]+a[2]), // max suffix
            a[3]+b[3], // sum
        };
    }

    // Constructors
    seg_tree(int n) { N = n; SEG.assign(2 * N, DEF); }
    seg_tree(int n, T def) { N = n; DEF = def; SEG.assign(2 * N, DEF); }

    // Mutators
    void pull(int p) { SEG[p] = combine(SEG[2 * p], SEG[2 * p + 1]); }
    void update(int p, T val) {
        if (p < 0 || p >= N) return;
        SEG[p += N] = val;
        for (p /= 2; p; p /= 2) pull(p);
    }

    // Accessors
    T get(int p) { return (p < 0 || p >= N ? DEF : SEG[p + N]); }
    void print() {
        cout << "\n";
        for (int i = 1; i < 2 * N; i++)
            cout << SEG[i][0] << " " << SEG[i][1] << " " << SEG[i][2] << " " << SEG[i][3] << "\n";
    }
    T query(int l, int r) { // [l, r]
        if (l < 0 || r < 0 || l >= N || r >= N || l > r) return DEF;
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
    seg_tree<array<long long, 4>> ST(n, {0, 0, 0, 0});
    for (int i = 0; i < n; i++) {
        long long x; cin >> x;
        ST.update(i, {max(x, 0LL), max(x, 0LL), max(x, 0LL), x});
    }
    for (int i = 0; i < q; i++) {
        long long a, b; cin >> a >> b;
        ST.update(a-1, {max(b, 0LL), max(b, 0LL), max(b, 0LL), b});
        cout << ST.query(0, n-1)[1] << "\n";
    }
}
