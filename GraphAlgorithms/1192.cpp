#include <bits/stdc++.h>

void dfs(int r, int c, std::vector<std::vector<bool>> &G, int N, int M) {
    if (r < 0 || r >= N || c < 0 || c >= M || G[r][c]) return;
    G[r][c] = true;

    dfs(r - 1, c, G, N, M);
    dfs(r + 1, c, G, N, M);
    dfs(r, c - 1, G, N, M);
    dfs(r, c + 1, G, N, M);
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, M; std::cin >> N >> M;

    std::vector<std::vector<bool>> G(N, std::vector<bool>(M));
    for (int i = 0; i < N; i++) {
        for (int q = 0; q < M; q++) {
            char c; std::cin >> c;
            G[i][q] = c == '#';
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int q = 0; q < M; q++) {
            if (!G[i][q]) { ans++; dfs(i, q, G, N, M); }
        }
    }

    std::cout << ans << "\n";
}
