#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N; std::cin >> N;

    std::vector<std::array<int, 3>> V(N);
    for (int i = 0; i < N; i++) {
        std::cin >> V[i][0] >> V[i][1];
        V[i][2] = i;
    }

    std::sort(V.begin(), V.end(), [](std::array<int, 3> a, std::array<int, 3> b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });

    std::vector<int> IC(N), CI(N);
    int mx = 0, mn = 1e9 + 1;
    for (int i = 0; i < N; i++) {
        CI[V[i][2]] = V[i][1] <= mx;
        mx = std::max(mx, V[i][1]);
    }
    for (int i = N-1; i >= 0; i--) {
        IC[V[i][2]] = V[i][1] >= mn;
        mn = std::min(mn, V[i][1]);
    }

    for (int &i : IC) std::cout << i << " ";
    std::cout << "\n";
    for (int &i : CI) std::cout << i << " ";
    std::cout << "\n";
}
