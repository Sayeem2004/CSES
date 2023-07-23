#include <bits/stdc++.h>

template<class T> struct combo_cache {
    std::vector<T> INV, IFT, FCT; T MXN = 1e6, MOD = 1e9+7; // Variables & Helpers

    combo_cache() { init(); } // Constructors
    combo_cache(T n) { MXN = n; init(); }
    combo_cache(T n, T m) { MXN = n; MOD = m; init(); }

    void init() { INV.assign(MXN + 1, 0); INV[0] = INV[1] = 1; // Initializers
        for (T i = 2; i <= MXN; i++) INV[i] = (MOD - MOD / i) * INV[MOD % i] % MOD;
        IFT.assign(MXN + 1, 0); IFT[0] = IFT[1] = 1;
        for (T i = 1; i <= MXN; i++) IFT[i] = IFT[i - 1] * INV[i] % MOD;
        FCT.assign(MXN + 1, 0); FCT[0] = FCT[1] = 1;
        for (T i = 1; i <= MXN; i++) FCT[i] = FCT[i - 1] * i % MOD; }

    T inv(T x) { return (x >= 0 && x <= MXN ? INV[x] : -1); } // Accessors
    T ift(T x) { return (x >= 0 && x <= MXN ? IFT[x] : -1); }
    T fct(T x) { return (x >= 0 && x <= MXN ? FCT[x] : -1); }
    T bin(T n, T k) { return (k > n || n < 0 || n > MXN ? -1 :
        fct(n) * ift(k) % MOD * ift(n-k) % MOD); }
    void print() { std::cout << "INV IFT FCT\n"; for (T i = 0; i <= MXN; i++)
        std::printf("%d %d %d", INV[i], IFT[i], FCT[i]); }
};

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long N; std::cin >> N;
    long long MX = N * (N + 1) / 2;

    const long long MOD = 1e9 + 7;
    combo_cache<long long> CC;

    if (MX % 2) { std::cout << 0 << "\n"; return 0; }

    std::vector<std::vector<long long>> DP(N + 1, std::vector<long long>(MX / 2 + 1, 0));
    DP[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int q = 0; q <= MX / 2; q++) {
            DP[i][q] = DP[i - 1][q];
            if (q - i >= 0) DP[i][q] += DP[i - 1][q - i];
            DP[i][q] %= MOD;
        }
    }

    std::cout << (DP[N][MX / 2] * CC.inv(2)) % MOD << "\n";
}
