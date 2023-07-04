#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, K; std::cin >> N >> K;

    std::vector<std::pair<int, int>> V(N);
    for (std::pair<int, int> &v : V) std::cin >> v.first >> v.second;
    std::sort(V.begin(), V.end(), [](std::pair<int, int> &a, std::pair<int, int> &b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });

    std::multiset<int> MS;
    for (int i = 0; i < K; i++) MS.insert(0);

    int ans = 0;
    for (int i = 0; i < N; i++) {
        std::multiset<int>::iterator it = MS.upper_bound(V[i].first);
        if (it == MS.begin()) continue;
        else it--;

        MS.erase(it); MS.insert(V[i].second); ans++;
    }

    std::cout << ans << "\n";
}
