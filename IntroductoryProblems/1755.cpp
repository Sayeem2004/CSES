#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    std::string S; std::cin >> S;
    int N = S.size();

    std::map<char, int> M;
    for (char c : S) M[c]++;

    std::string ans = S;
    int pos = 0, cnt = 0;

    for (std::pair<char, int> P : M) {
        if (P.second % 2 == 1) {
            ans[N/2] = P.first;
            cnt++;
        }

        for (int i = 2; i <= P.second; i += 2) {
            ans[pos] = P.first;
            ans[N-pos-1] = P.first;
            pos++;
        }
    }

    if (cnt > 1) std::cout << "NO SOLUTION\n";
    else std::cout << ans << '\n';
}
