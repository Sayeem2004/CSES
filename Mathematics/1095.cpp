#include <bits/stdc++.h>

template<class T> struct num_util {
    T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
    T lcm(T a, T b) { return a / gcd(a, b) * b; }
    T pow(T a, T b, T m) { if (!b) return 1; T r = pow(a*a%m, b/2, m); return b&1 ? r*a%m : r; }
};

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int T; std::cin >> T; while (T--) {
        long long A, B; std::cin >> A >> B;
        num_util<long long> NU;
        std::cout << NU.pow(A, B, 1e9+7) << "\n";
    }
}
