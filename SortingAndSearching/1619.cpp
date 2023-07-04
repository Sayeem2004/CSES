#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N; std::cin >> N;

    std::vector<std::pair<int, int>> V(N*2);
    for (int i = 0; i < N*2; i++) {
        std::cin >> V[i].first;
        V[i].second = i % 2;
    }
    std::sort(V.begin(), V.end());

    int ans = 0, curr = 0;
    for (int i = 0; i < N*2; i++) {
        if (V[i].second == 0) curr++;
        else curr--;

        ans = std::max(ans, curr);
    }

    std::cout << ans << "\n";
}
