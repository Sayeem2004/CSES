#include <bits/stdc++.h>

const int N = 7;
bool V[N+2][N+2];
const int DR[] = {1, -1, 0, 0}, DC[] = {0, 0, 1, -1};

int solve(int p, int r, int c, std::string &S) {
    if (r == N && c == 1) return p == N*N-1;
    if (p == N*N-1) return 0;

    if (V[r-1][c] && V[r+1][c] && !V[r][c-1] && !V[r][c+1]) return 0;
    if (!V[r-1][c] && !V[r+1][c] && V[r][c-1] && V[r][c+1]) return 0;

    V[r][c] = 1;
    int ans = 0;

    for (int i = 0; i < 4; i++) {
        if (S[p] == 'D' && i != 0) continue;
        if (S[p] == 'U' && i != 1) continue;
        if (S[p] == 'R' && i != 2) continue;
        if (S[p] == 'L' && i != 3) continue;

        int nr = r + DR[i], nc = c + DC[i];
        if (!V[nr][nc]) ans += solve(p+1, nr, nc, S);
    }

    V[r][c] = 0;
    return ans;
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    std::string S; std::cin >> S;
    for (int i = 0; i < N+2; i++) V[0][i] = V[N+1][i] = V[i][0] = V[i][N+1] = 1;
    std::cout << solve(0, 1, 1, S) << "\n";
}
