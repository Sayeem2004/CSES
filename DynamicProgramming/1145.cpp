#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N; std::cin >> N;
    std::multiset<int> MS;

    for (int i = 0; i < N; i++) {
        int x; std::cin >> x;
        std::multiset<int>::iterator it = MS.lower_bound(x);

        if (it == MS.end()) MS.insert(x);
        else { MS.erase(it); MS.insert(x); }
    }

    std::cout << MS.size() << "\n";
}
