#include <bits/stdc++.h>

template<typename T> struct combo_cache {
    std::vector<T> INV, IFT, FCT, DRG; T MXN, MOD; // Variables
    combo_cache(T n = 1e6, T m = 1e9+7) : MXN(n), MOD(m) { init(); } // Constructors

    void init() { INV.assign(MXN + 1, 0); INV[0] = INV[1] = 1; // Mutators
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
    T pow(T n, T k) { T r = 1; while (k > 0) { if (k&1) r = r*n%MOD; n = n*n%MOD; k >>= 1; } return r; }
    T bin(T n, T k) { return (k < n ? fct(n) * ift(k) % MOD * ift(n-k) % MOD : -1); }
    T str(T n, T k) { return bin(n + k - 1, n); }
};

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long MOD = 1e9 + 7;
    combo_cache<long long> CC(10, MOD);
    long long N; std::cin >> N;

    std::vector<long long> P(N), K(N);
    for (int i = 0; i < N; i++) std::cin >> P[i] >> K[i];

    long long num = 1, sum = 1, prd = 1, cnt = 1;
    for (int i = 0; i < N; i++) {
        num = num * (K[i] + 1) % MOD;
        sum = sum * (CC.pow(P[i], K[i] + 1) - 1) % MOD * CC.pow(P[i] - 1, MOD - 2) % MOD;
        prd = CC.pow(prd, K[i] + 1) * CC.pow(CC.pow(P[i], (K[i] * (K[i] + 1) / 2)), cnt) % MOD;
        cnt = cnt * (K[i] + 1) % (MOD - 1);
    }

    std::cout << num << " " << sum << " " << prd << "\n";
}
