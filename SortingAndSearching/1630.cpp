#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    typedef std::pair<long long, long long> node;
    int N; std::cin >> N;

    std::vector<node> V(N);
    for (node &v : V) std::cin >> v.first >> v.second;
    std::sort(V.begin(), V.end(), [](node a, node b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });

    long long curr = 0, ans = 0;
    for (node v : V) {
        curr += v.first;
        ans += v.second - curr;
    }

    std::cout << ans << "\n";
}
