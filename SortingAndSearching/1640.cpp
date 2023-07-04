#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, X; std::cin >> N >> X;

    std::vector<std::pair<int, int>> V(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> V[i].first;
        V[i].second = i + 1;
    }
    std::sort(V.begin(), V.end());

    int l = 0, r = N - 1;
    while (l < r) {
        if (V[l].first + V[r].first > X) r--;
        else if (V[l].first + V[r].first < X) l++;
        else {
            std::cout << V[l].second << " " << V[r].second << "\n";
            return 0;
        }
    }

    std::cout << "IMPOSSIBLE\n";
}
