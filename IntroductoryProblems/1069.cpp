#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    std::string S; std::cin >> S;

    int ans = 0, cnt = 1;
    for (int i = 1; i < S.size(); i++) {
        if (S[i] == S[i-1]) cnt++;
        else { ans = std::max(ans, cnt); cnt = 1; }
    }

    std::cout << std::max(ans, cnt) << '\n';
}
