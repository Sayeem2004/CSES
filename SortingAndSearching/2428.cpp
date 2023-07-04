#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, K; std::cin >> N >> K;
    std::vector<int> V(N);
    for (int &v : V) std::cin >> v;

    std::map<int, int> M;
    long long ans = 0, l = 0;

    for (int i = 0; i < N; i++) {
        M[V[i]]++;

        while (M.size() > K && l <= i) {
            if (--M[V[l]] == 0) M.erase(V[l]);
            l++;
        }

        ans += i - l + 1;
    }

    std::cout << ans << "\n";
}
