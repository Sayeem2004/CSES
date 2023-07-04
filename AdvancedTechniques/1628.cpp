#include <bits/stdc++.h>

std::vector<long long> subset(std::vector<long long> &V) {
    int N = V.size();
    std::vector<long long> RET;

    for (int i = 0; i < (1<<N); i++) {
        long long sum = 0;
        for (int q = 0; q < N; q++) {
            if (i & (1<<q)) sum += V[q];
        }
        RET.push_back(sum);
    }

    return RET;
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, X; std::cin >> N >> X;

    std::vector<long long> V(N);
    for (long long& v : V) std::cin >> v;
    std::sort(V.begin(), V.end());

    std::vector<long long> A(N/2), B(N-N/2);
    for (int i = 0; i < N/2; i++) A[i] = V[i];
    for (int i = N/2; i < N; i++) B[i-N/2] = V[i];

    std::vector<long long> SA = subset(A);
    std::vector<long long> SB = subset(B);
    std::sort(SB.begin(), SB.end());

    long long ans = 0;
    for (long long sa : SA) {
        std::vector<long long>::iterator it1 = std::lower_bound(SB.begin(), SB.end(), X-sa);
        std::vector<long long>::iterator it2 = std::upper_bound(SB.begin(), SB.end(), X-sa);
        ans += it2 - it1;
    }

    std::cout << ans << "\n";
}
