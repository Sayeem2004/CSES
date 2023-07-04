#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N; std::cin >> N;

    std::map<int, int> M;
    int ans = 1, l = -1;

    for (int i = 0; i < N; i++) {
        int x; std::cin >> x;
        if (M.count(x)) l = std::max(l, M[x]);

        ans = std::max(ans, i - l);
        M[x] = i;
    }

    std::cout << ans << "\n";
}
