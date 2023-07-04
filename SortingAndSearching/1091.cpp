#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, Q; std::cin >> N >> Q;

    std::multiset<int> S;
    for (int i = 0; i < N; i++) {
        int x; std::cin >> x;
        S.insert(x);
    }

    for (int i = 0; i < Q; i++) {
        int c; std::cin >> c;
        std::set<int>::iterator itr = S.upper_bound(c);

        if (itr == S.begin()) std::cout << -1 << "\n";
        else {
            std::cout << *(--itr) << "\n";
            S.erase(itr);
        }
    }
}
