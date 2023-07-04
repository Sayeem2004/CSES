#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template <typename T> using ordered_set = __gnu_pbds::tree<
    T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update // find_by_order, order_of_key
>;

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, K; std::cin >> N >> K;
    std::vector<std::pair<int, int>> V(N);
    for (int i = 0; i < N; i++) {
        std::cin >> V[i].first;
        V[i].second = i;
    }

    ordered_set<std::pair<int, int>> S;
    for (int i = 0; i < N; i++) {
        S.insert(V[i]);
        if (i < K-1) continue;
        if (i > K-1) S.erase(S.find(V[i - K]));

        std::cout << (*S.find_by_order((K - 1) / 2)).first << " ";
    }

    std::cout << "\n";
}
