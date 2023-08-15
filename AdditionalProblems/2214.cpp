#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long N, K; std::cin >> N >> K;

    std::vector<long long> ANS(N); long long L = 1, R = N, P = 0;
    for (long long i = N-1; i >= 0; i--) {
        if (K >= i) { ANS[P++] = R--; K -= i; }
        else { ANS[P++] = L++; }
    }

    for (long long a : ANS) std::cout << a << " ";
    std::cout << "\n";
}
