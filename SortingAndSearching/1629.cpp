#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N; std::cin >> N;

    std::vector<std::pair<int, int>> V(N);
    for (int i = 0; i < N; i++) {
        int s, e; std::cin >> s >> e;
        V[i] = {e, s};
    }
    std::sort(V.begin(), V.end());

    int ans = 0, curr = 0;
    for (int i = 0; i < N; i++) {
        if (V[i].second >= curr) {
            ans++; curr = V[i].first;
        }
    }

    std::cout << ans << "\n";
}
