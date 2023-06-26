#include <bits/stdc++.h>

int solve(int r, std::vector<std::string> &BOARD, std::vector<bool> &COL,
    std::vector<bool> &DIAG1, std::vector<bool> &DIAG2) {

    if (r == 8) return 1;

    int ans = 0;
    for (int c = 0; c < 8; c++) {
        if (BOARD[r][c] == '*') continue;
        if (COL[c] || DIAG1[r+c] || DIAG2[r+7-c]) continue;

        COL[c] = DIAG1[r+c] = DIAG2[r+7-c] = true;
        ans += solve(r+1, BOARD, COL, DIAG1, DIAG2);
        COL[c] = DIAG1[r+c] = DIAG2[r+7-c] = false;
    }

    return ans;
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    std::vector<std::string> BOARD(8);
    for (std::string &s : BOARD) std::cin >> s;

    std::vector<bool> COL(8, false), DIAG1(15, false), DIAG2(15, false);
    std::cout << solve(0, BOARD, COL, DIAG1, DIAG2) << '\n';
}
