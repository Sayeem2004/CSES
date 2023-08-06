#include <bits/stdc++.h>

template<typename T> struct sparse_table {
    std::vector<std::vector<T>> ST; int N, K; T (*OP)(T, T); // Variables & Constructors
    sparse_table(int n, std::vector<T> &V, T (*c)(T, T) = [](T a, T b) { return std::min(a, b); }) : N(n), OP(c) {
        K = log2(N); ST.assign(K+1, std::vector<T>(N)); std::copy(V.begin(), V.end(), ST[0].begin());
        for (int k = 1; k <= K; k++) for (int i = 0; i + (1 << k) <= N; i++)
        ST[k][i] = OP(ST[k-1][i], ST[k-1][i+(1<<(k-1))]); }

    int log2(int n) { return 31 - __builtin_clz(n); } // Helpers & Accessors
    void print() { for (auto V : ST) { for (T v : V) std::cout << v << " "; std::cout << "\n"; } }
    T idem(int l, int r) { int k = log2(r-l+1); return OP(ST[k][l], ST[k][r-(1<<k)+1]); } // [l, r]
    T query(int l, int r, int d = 0) { T val = d; for (int i = K; i >= 0; i--) {
        if (1<<i <= r - l + 1) { val = OP(val, ST[i][l]); l += (1<<i); } } return val; }
};

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long N, Q; std::cin >> N >> Q;
    std::vector<long long> V(N);
    for (long long &v : V) std::cin >> v;

    sparse_table<long long> ST(N, V, [](long long a, long long b) { return a+b; });

    for (int i = 0; i < Q; i++) {
        int l, r; std::cin >> l >> r;
        std::cout << ST.query(l-1, r-1) << "\n";
    }
}
