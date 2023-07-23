#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long N; std::cin >> N;
    std::map<long long, long long> IND;
    std::vector<long long> S(N), E(N), V(N);

    for (int i = 0; i < N; i++) {
        std::cin >> S[i] >> E[i] >> V[i];
        IND[S[i]] = IND[++E[i]] = 0;
    }

    long long cnt = 0;
    for (std::pair<long long, long long> p : IND) IND[p.first] = cnt++;

    std::vector<std::vector<std::array<long long, 2>>> SPEC(cnt);
    for (int i = 0; i < N; i++) {
        SPEC[IND[E[i]]].push_back({IND[S[i]], V[i]});
    }

    std::vector<long long> DP(cnt, 0);
    for (int i = 0; i < cnt; i++) {
        if (i > 0) DP[i] = DP[i - 1];
        for (std::array<long long, 2> p : SPEC[i]) {
            DP[i] = std::max(DP[i], DP[p[0]] + p[1]);
        }
    }

    std::cout << DP[cnt - 1] << "\n";
}
