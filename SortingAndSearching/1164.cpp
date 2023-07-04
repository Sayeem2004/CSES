#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    typedef std::array<int, 3> node;
    int N; std::cin >> N;

    std::vector<node> V(N);
    for (int i = 0; i < N; i++) {
        std::cin >> V[i][0] >> V[i][1];
        V[i][2] = i;
    }
    std::sort(V.begin(), V.end());

    int mn = 1;
    std::vector<int> A(N);
    std::priority_queue<node, std::vector<node>, std::greater<node>> PQ;

    A[V[0][2]] = mn;
    PQ.push({V[0][1], mn, 0});
    for (int i = 1; i < N; i++) {
        node curr = PQ.top();

        if (V[i][0] > curr[0]) {
            PQ.pop(); A[V[i][2]] = curr[1];
            PQ.push({V[i][1], curr[1], i});
        } else {
            mn++; A[V[i][2]] = mn;
            PQ.push({V[i][1], mn, i});
        }
    }

    std::cout << mn << "\n";
    for (int i = 0; i < N; i++) {
        std::cout << A[i] << " \n"[i == N - 1];
    }
}
