#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N; std::cin >> N;

    std::vector<int> V(N);
    for (int &v : V) std::cin >> v;
    std::sort(V.begin(), V.end());

    int med = V[N / 2];
    if (N % 2 == 0) med = (med + V[N / 2 - 1]) / 2;

    long long ans = 0;
    for (int i = 0; i < N; i++) ans += std::abs(V[i] - med);
    std::cout << ans << "\n";
}
