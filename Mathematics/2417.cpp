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

    int N, MX = 0; std::cin >> N;
    std::unordered_map<int, int> M;
    for (int i = 0; i < N; i++) { int x; std::cin >> x; M[x]++; MX = std::max(MX, x); }

    long long ans = 0;
    num_cache<long long> NC(MX);
    for (int i = 1; i <= MX; i++) {
        if (!NC.mob(i)) continue;
        long long cnt = 0;

        for (int q = i; q <= MX; q += i) cnt += M[q];
        ans += NC.mob(i) * cnt * (cnt - 1) / 2;
    }

    std::cout << ans << "\n";
}
