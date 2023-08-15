#include <bits/stdc++.h>

long long get(long long v, int i, std::vector<int> &P) { return (v / (long long) P[i]) % 10; }
void set(long long &v, int i, int x, std::vector<int> &P) { v += (long long) P[i] * (x - get(v, i, P)); }
long long convert(std::vector<int> &V) { long long res = 0; for (int v : V) res = res * 10 + v; return res; }

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    std::vector<int> V = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> P = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
    long long root = convert(V);

    std::vector<int> A(9);
    for (int &a : A) std::cin >> a;
    long long target = convert(A);

    std::unordered_map<long long, int> DIST;
    std::queue<long long> Q;
    Q.push(root); DIST[root] = 0;

    while (!Q.empty()) {
        long long node = Q.front(); Q.pop();

        if (node == target) { std::cout << DIST[node] << "\n"; break; }

        for (int i = 0; i < 9; i++) {
            if (i % 3 == 2) continue;
            long long next = node;
            set(next, i, get(node, i + 1, P), P);
            set(next, i + 1, get(node, i, P), P);
            if (!DIST.count(next)) { DIST[next] = DIST[node] + 1; Q.push(next); }
        }

        for (int i = 0; i < 6; i++) {
            long long next = node;
            set(next, i, get(node, i + 3, P), P);
            set(next, i + 3, get(node, i, P), P);
            if (!DIST.count(next)) { DIST[next] = DIST[node] + 1; Q.push(next); }
        }
    }
}
