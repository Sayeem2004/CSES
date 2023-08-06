#include <bits/stdc++.h>

void dfs(int v, std::vector<int> &CNT, std::vector<std::vector<int>> &ADJ) {
    for (int u : ADJ[v]) {
        dfs(u, CNT, ADJ);
        CNT[v] += CNT[u] + 1;
    }
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N; std::cin >> N;
    std::vector<std::vector<int>> ADJ(N);
    for (int i = 1; i < N; i++) {
        int x; std::cin >> x;
        ADJ[x - 1].push_back(i);
    }

    std::vector<int> ANS(N);
    dfs(0, ANS, ADJ);

    for (int i = 0; i < N; i++) std::cout << ANS[i] << " ";
    std::cout << "\n";
}
