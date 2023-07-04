#include <bits/stdc++.h>

bool check(std::vector<long long> &V, long long t, long long x) {
    long long curr = 0;
    for (int i = 0; i < V.size(); i++) {
        curr += t / V[i];
        if (curr >= x) return true;
    }
    return curr >= x;
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long N, X; std::cin >> N >> X;
    std::vector<long long> V(N);
    for (long long &v : V) std::cin >> v;

    long long  lo = 0, hi = 1e18;
    while (lo < hi) {
        long long mid = (lo + hi) / 2;

        if (check(V, mid, X)) hi = mid;
        else lo = mid + 1;
    }

    std::cout << lo << "\n";
}
