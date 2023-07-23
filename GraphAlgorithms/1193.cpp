#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, M; std::cin >> N >> M;
    int sr, sc, er, ec;

    std::vector<std::vector<bool>> G(N, std::vector<bool>(M));
    for (int i = 0; i < N; i++) {
        for (int q = 0; q < M; q++) {
            char c; std::cin >> c;
            G[i][q] = c == '#';

            if (c == 'A') { sr = i; sc = q; }
            if (c == 'B') { er = i; ec = q; }
        }
    }

    std::vector<std::pair<int, int>> D = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    std::vector<std::vector<int>> P(N, std::vector<int>(M, -1));
    std::queue<std::pair<int, int>> Q;

    Q.push({sr, sc});
    while (!Q.empty()) {
        std::pair<int, int> curr = Q.front(); Q.pop();
        int r = curr.first, c = curr.second;

        if (G[r][c]) continue; G[r][c] = true;

        for (std::pair<int, int> d : D) {
            int nr = r + d.first, nc = c + d.second;
            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if (G[nr][nc]) continue;

            P[nr][nc] = r * M + c;
            Q.push({nr, nc});
        }
    }

    if (P[er][ec] == -1) { std::cout << "NO\n"; return 0; }

    std::cout << "YES\n";
    std::vector<char> ANS;
    int r = er, c = ec;

    while (r != sr || c != sc) {
        int pr = P[r][c] / M, pc = P[r][c] % M;

        if (pr == r) {
            if (pc < c) ANS.push_back('R');
            else ANS.push_back('L');
        } else {
            if (pr < r) ANS.push_back('D');
            else ANS.push_back('U');
        }

        r = pr; c = pc;
    }

    std::reverse(ANS.begin(), ANS.end());
    std::cout << ANS.size() << "\n";
    for (char c : ANS) std::cout << c;
    std::cout << "\n";
}
