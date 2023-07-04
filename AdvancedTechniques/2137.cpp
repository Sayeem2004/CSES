#include <bits/stdc++.h>
#pragma GCC target("popcnt")

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N; std::cin >> N;

    std::bitset<3000> V[N];
    for (int i = 0; i < N; i++) std::cin >> V[i];

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        for (int q = i+1; q < N; q++) {
            int val = (V[i] & V[q]).count();
            ans += val*(val-1)/2;
        }
    }

    std::cout << ans << "\n";
}
