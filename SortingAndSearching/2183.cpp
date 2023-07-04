#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N; std::cin >> N;

    std::vector<long long> V(N);
    for (long long &v : V) std::cin >> v;
    std::sort(V.begin(), V.end());

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        if (V[i] > ans + 1) break;
        ans += V[i];
    }

    std::cout << ans + 1 << "\n";
}
