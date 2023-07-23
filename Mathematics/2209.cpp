#include <bits/stdc++.h>

template<class T> struct num_util {
    T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
    T lcm(T a, T b) { return a / gcd(a, b) * b; }
    T pow(T a, T b, T m) { if (!b) return 1; T r = pow(a*a%m, b/2, m); return b&1 ? r*a%m : r; }
};

template<class T> struct combo_cache {
    std::vector<T> INV, IFT, FCT, DRG; T MXN = 1e6, MOD = 1e9+7; // Variables
    combo_cache(T n = 1e6, T m = 1e9+7) { MXN = n; MOD = m; init(); } // Constructor

    void init() { INV.assign(MXN + 1, 0); INV[0] = INV[1] = 1; // Initializer
        for (T i = 2; i <= MXN; i++) INV[i] = (MOD - MOD/i) * INV[MOD%i] % MOD;
        IFT.assign(MXN + 1, 0); IFT[0] = IFT[1] = 1;
        for (T i = 1; i <= MXN; i++) IFT[i] = IFT[i-1] * INV[i] % MOD;
        FCT.assign(MXN + 1, 0); FCT[0] = FCT[1] = 1;
        for (T i = 1; i <= MXN; i++) FCT[i] = FCT[i-1] * i % MOD;
        DRG.assign(MXN + 1, 0); DRG[0] = 1; DRG[1] = 0;
        for (T i = 2; i <= MXN; i++) DRG[i] = (i-1) * (DRG[i-1] + DRG[i-2]) % MOD; }

    T inv(T n) { return (n >= 0 && n <= MXN ? INV[n] : -1); } // Accessors
    T ift(T n) { return (n >= 0 && n <= MXN ? IFT[n] : -1); }
    T fct(T n) { return (n >= 0 && n <= MXN ? FCT[n] : -1); }
    T drg(T n) { return (n >= 0 && n <= MXN ? DRG[n] : -1); }
    T cat(T n) { return (n >= 0 && n <= MXN/2 ? bin(2*n, n) * inv(n+1) % MOD : -1); }
    T bin (T n, T k) { return (k < n ? fct(n) * ift(k) % MOD * ift(n-k) % MOD : -1); }
};

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long N, M; std::cin >> N >> M;
    combo_cache<long long> CC;
    num_util<long long> NU;

    long long ans = 0, mod = 1e9+7;
    for (int i = 0; i < N; i++) {
        ans += NU.pow(M, NU.gcd(i, N), mod);
        ans %= mod;
    }

    ans *= CC.inv(N); ans %= mod;
    std::cout << ans << "\n";
}
