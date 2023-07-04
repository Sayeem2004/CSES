#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, Q; std::cin >> N >> Q;

    std::set<int> P;
    P.insert(0); P.insert(N);
    std::multiset<int> D;
    D.insert(N);

    for (int i = 0; i < Q; i++) {
        int x; std::cin >> x;

        std::set<int>::iterator it = P.upper_bound(x);
        int r = *it, l = *(--it);

        D.erase(D.find(r - l));
        D.insert(r - x); D.insert(x - l);
        P.insert(x);

        std::cout << *D.rbegin() << " ";
    }

    std::cout << "\n";
}
