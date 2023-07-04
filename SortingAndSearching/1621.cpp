#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N; std::cin >> N;

    std::set<int> S;
    for (int i = 0; i < N; i++) {
        int x; std::cin >> x;
        S.insert(x);
    }

    std::cout << S.size() << "\n";
}
