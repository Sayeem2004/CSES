#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, M; std::cin >> N >> M;

    std::vector<std::vector<int>> G(N, std::vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int q = 0; q < N; q++) {
            char c; std::cin >> c;
            G[i][q] = (c == '*');
        }
    }

    for (int i = 0; i < N; i++)
        for (int q = 1; q < N; q++)
            G[i][q] += G[i][q - 1];

    for (int i = 1; i < N; i++)
        for (int q = 0; q < N; q++)
            G[i][q] += G[i - 1][q];

    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;

        int ans = G[x2][y2];
        if (x1 > 0) ans -= G[x1 - 1][y2];
        if (y1 > 0) ans -= G[x2][y1 - 1];
        if (x1 > 0 && y1 > 0) ans += G[x1 - 1][y1 - 1];

        std::cout << ans << "\n";
    }
}
