#include <bits/stdc++.h>
using namespace std;

template<class T> struct mod_cache {
    T MOD = 1e9+7; // Variables & Helpers

    mod_cache() { } // Constructors
    mod_cache(T m) { MOD = m; }

    T add(T a, T b) { return (a + b) % MOD; } // Operations
    T sub(T a, T b) { return ((a - b) % MOD + MOD) % MOD; }
    T mul(T a, T b) { return (a * b) % MOD; }
    T div(T a, T b) { return (a * inv(b)) % MOD; }
    T pow(T a, T b) { T res = 1; while (b) { if (b & 1) res = mul(res, a);
        a = mul(a, a); b >>= 1; } return res; }

    T gcd(T a, T b) { return (b == 0 ? a : gcd(b, a % b)); } // Extended Operations
    T inv(T a) { return (a == 1 ? 1 : (MOD - MOD / a) * inv(MOD % a) % MOD); }
    bool aover(T a, T b) { return __builtin_add_overflow_p(a, b, (T) 0); }
    bool sover(T a, T b) { return __builtin_sub_overflow_p(a, b, (T) 0); }
    bool mover(T a, T b) { return __builtin_mul_overflow_p(a, b, (T) 0); }
    bool dover(T a, T b) { return __builtin_div_overflow_p(a, b, (T) 0); }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long n, k; cin >> n >> k;
    vector<long long> V(k);
    for (long long &v : V) cin >> v;

    long long ans = 0;
    mod_cache<long long> MC;
    for (long long i = 1; i < 1 << k; i++) {
        long long prod = 1, cnt = 0;
        bool br = false;

        for (long long q = 0; q < k; q++) {
            if (i & (1 << q)) {
                if (MC.mover(prod, V[q])) { br = true; break; }
                prod *= V[q]; cnt++;
            }
        }

        if (!br) ans += (cnt % 2 ? 1 : -1) * n / prod;
    }

    cout << ans << "\n";
}
