#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int T; std::cin >> T; while (T--) {
        long long R, C; std::cin >> R >> C;
        long long val = 0;

        if (R > C) {
            val = R * R - R + 1;

            if (R % 2 == 0) val += R - C;
            else val -= R - C;
        } else {
            val = C * C - C + 1;

            if (C % 2 == 0) val -= C - R;
            else val += C - R;
        }

        std::cout << val << "\n";
    }
}
