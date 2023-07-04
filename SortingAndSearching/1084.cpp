#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, M, K; std::cin >> N >> M >> K;

    std::vector<int> A(N), B(M);
    for (int& a : A) std::cin >> a;
    for (int& b : B) std::cin >> b;

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());

    int ans = 0, pos = 0;
    for (int i = 0; i < M; i++) {
        while (pos < N && A[pos] < B[i] - K) pos++;
        if (pos < N && A[pos] <= B[i] + K) { ans++; pos++; }
    }

    std::cout << ans << "\n";
}
