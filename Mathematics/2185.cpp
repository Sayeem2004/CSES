#include <bits/stdc++.h>

template<typename T> struct num_cache {
    std::vector<T> LPF, MOB; T MXN, MOD; // Variables
    num_cache(T n = 1e6, T m = 1e9+7) : MXN(n), MOD(m) { // Constructors
        LPF.assign(MXN + 1, 0); MOB.assign(MXN + 1, 1); for (int i = 2; i <= MXN; i++) {
        if (!LPF[i]) { for (int q = i; q <= MXN; q += i) if (!LPF[q]) LPF[q] = i; }
        if (LPF[i/LPF[i]] == LPF[i]) MOB[i] = 0; else MOB[i] = -MOB[i/LPF[i]]; } }

    T lpf(T n) { return (n >= 0 && n <= MXN ? LPF[n] : -1); } // Accessors
    T mob(T n) { return (n >= 0 && n <= MXN ? MOB[n] : -2); }
    T inv(T x) { return (x == 1 ? 1 : (MOD - MOD / x) * inv(MOD % x) % MOD); }
    T pow(T n, T k) { T r = 1; while (k > 0) { if (k&1) r = r*n%MOD; n = n*n%MOD; k >>= 1; } return r; }

    bool aover(T a, T b) { return __builtin_add_overflow_p(a, b, (T) 0); } // Helpers
    bool sover(T a, T b) { return __builtin_sub_overflow_p(a, b, (T) 0); }
    bool mover(T a, T b) { return __builtin_mul_overflow_p(a, b, (T) 0); }
    bool dover(T a, T b) { return __builtin_div_overflow_p(a, b, (T) 0); }
};

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long N, K; std::cin >> N >> K;
    std::vector<long long> V(K);
    for (long long &v : V) std::cin >> v;

    long long ans = 0;
    num_cache<long long> NC(10);
    for (long long i = 1; i < 1 << K; i++) {
        long long prod = 1, cnt = 0;
        bool br = false;

        for (long long q = 0; q < K; q++) {
            if (i & (1 << q)) {
                if (NC.mover(prod, V[q])) { br = true; break; }
                prod *= V[q]; cnt++;
            }
        }

        if (!br) ans += (cnt % 2 ? 1 : -1) * N / prod;
    }

    std::cout << ans << "\n";
}
