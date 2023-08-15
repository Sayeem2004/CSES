#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long N; std::cin >> N;
    std::vector<long long> V(N);
    for (long long &v : V) std::cin >> v;

    long long ans = 0;
    std::stack<std::pair<long long, long long>> S;
    for (int i = 0; i < N; i++) {
        long long pos = i;
        while (!S.empty() && S.top().first > V[i]) {
            std::pair<long long, long long> top = S.top(); S.pop();
            ans = std::max(ans, top.first * (i - top.second));
            pos = top.second;
        }
        S.push({V[i], pos});
    }

    while (!S.empty()) {
        std::pair<long long, long long> top = S.top(); S.pop();
        ans = std::max(ans, top.first * (N - top.second));
    }

    std::cout << ans << "\n";
}
