#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, M; std::cin >> N >> M;

    std::vector<int> V(N);
    for (int& v : V) std::cin >> v;
    std::sort(V.begin(), V.end());

    int ans = 0;
    for (int i = 0, q = N-1; i <= q; ) {
        if (V[i] + V[q] <= M) { ans++; i++; q--; }
        else { ans++; q--; }
    }

    std::cout << ans << "\n";
}
