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

    std::vector<std::array<int, 3>> S;
    for (int i = 0; i < N; i++) {
        for (int q = i+1; q < N; q++) {
            S.push_back({V[i].first + V[q].first, V[i].second, V[q].second});
        }
    }
    std::sort(S.begin(), S.end());

    int l = 0, r = S.size() - 1;
    while (l < r) {
        if (S[l][0] + S[r][0] == X) {
            if (S[l][1] == S[r][1] || S[l][1] == S[r][2]) { l++; continue; }
            if (S[l][2] == S[r][1] || S[l][2] == S[r][2]) { l++; continue; }

            std::cout << S[l][1] << " " << S[l][2] << " " << S[r][1] << " " << S[r][2] << "\n";
            return 0;
        } else if (S[l][0] + S[r][0] < X) l++;
        else r--;
    }

    int l2 = 0, r2 = S.size() - 1;
    while (l2 < r2) {
        if (S[l2][0] + S[r2][0] == X) {
            if (S[l2][1] == S[r2][1] || S[l2][1] == S[r2][2]) { r2--; continue; }
            if (S[l2][2] == S[r2][1] || S[l2][2] == S[r2][2]) { r2--; continue; }

            std::cout << S[l2][1] << " " << S[l2][2] << " " << S[r2][1] << " " << S[r2][2] << "\n";
            return 0;
        } else if (S[l2][0] + S[r2][0] < X) l2++;
        else r2--;
    }

    std::cout << "IMPOSSIBLE\n";
}
