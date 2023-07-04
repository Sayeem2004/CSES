#include <bits/stdc++.h>

long long solve(long long pos, long long sm1, long long sm2, std::vector<long long> &V) {
    if (pos == V.size()) return std::abs(sm1 - sm2);

    return std::min(
        solve(pos + 1, sm1 + V[pos], sm2, V),
        solve(pos + 1, sm1, sm2 + V[pos], V)
    );
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long N; std::cin >> N;

    std::vector<long long> V(N);
    for (long long &v : V) std::cin >> v;

    std::cout << solve(0, 0, 0, V) << "\n";
}
