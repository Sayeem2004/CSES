#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N; std::cin >> N;
    std::vector<int> V(N);
    for (int &v : V) std::cin >> v;

    std::stack<int> S;
    for (int i = 0; i < N; i++) {
        while (!S.empty() && V[S.top()] >= V[i]) S.pop();

        if (S.empty()) std::cout << "0 ";
        else std::cout << S.top() + 1 << " ";

        S.push(i);
    }

    std::cout << "\n";
}
