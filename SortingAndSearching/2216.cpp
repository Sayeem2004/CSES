#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N; std::cin >> N;

    std::unordered_map<int, int> M;
    for (int i = 0; i < N; i++) {
        int x; std::cin >> x;
        M[x] = i;
    }

    int ans = 1, curr = 2;
    while (curr <= N) {
        if (M[curr] < M[curr - 1]) ans++;
        curr++;
    }

    std::cout << ans << "\n";
}
