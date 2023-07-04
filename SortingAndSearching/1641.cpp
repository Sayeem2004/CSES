#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long N, X; std::cin >> N >> X;

    std::vector<std::pair<int, int>> V(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> V[i].first;
        V[i].second = i + 1;
    }
    std::sort(V.begin(), V.end());

    for (int i = 0; i < N; i++) {
        int l = i + 1, r = N - 1;
        long long rem = X - V[i].first;
        if (rem < 0) continue;

        while (l < r) {
            long long sum = V[l].first + V[r].first;

            if (sum == rem) break;
            else if (sum < rem) l++;
            else r--;
        }

        if (l < r && V[l].first + V[r].first == rem) {
            std::cout << V[i].second << " " << V[l].second << " " << V[r].second << "\n";
            return 0;
        }
    }

    std::cout << "IMPOSSIBLE\n";
}
