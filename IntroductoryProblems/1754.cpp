#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int T; std::cin >> T; while (T--) {
        int A, B; std::cin >> A >> B;

        if (A > 2 * B || B > 2 * A) std::cout << "NO\n";
        else if ((A + B) % 3 == 0) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
}
