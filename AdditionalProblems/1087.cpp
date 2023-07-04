#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    std::string S; std::cin >> S;

    std::map<char, int> M;
    int cnt = 0, pos = 0;
    std::string ans = "";

    while ((long long) pos < S.size()) {
        M[S[pos]]++;
        bool flag = M['A'] > 0 && M['T'] > 0 &&
                    M['C'] > 0 && M['G'] > 0;

        if (flag) { cnt++; ans += S[pos]; M.clear(); }
        pos++;
    }

    if (M['A'] == 0) ans += 'A';
    else if (M['T'] == 0) ans += 'T';
    else if (M['C'] == 0) ans += 'C';
    else if (M['G'] == 0) ans += 'G';

    std::cout << ans << "\n";
}
