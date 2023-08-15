#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N; std::cin >> N;
    std::vector<int> V(N-2), D(N);
    for (int i = 0; i < N-2; i++) { std::cin >> V[i]; V[i]--; D[V[i]]++; }

    std::set<int> S;
    for (int i = 0; i < N; i++) if (D[i] == 0) S.insert(i);

    std::vector<std::pair<int, int>> ANS;
    for (int i = 0; i < N-2; i++) {
        std::set<int>::iterator it = S.begin();
        ANS.push_back({*it+1, V[i]+1}); S.erase(it);
        if (--D[V[i]] == 0) S.insert(V[i]);
    }

    std::set<int>::iterator it = S.begin();
    ANS.push_back({*it+1, N}); S.erase(it);

    for (int i = 0; i < N-1; i++) std::cout << ANS[i].first << " " << ANS[i].second << "\n";
}
