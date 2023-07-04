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

    int N, Q; std::cin >> N >> Q;

    ordered_set<std::pair<int, int>> OS;
    OS.insert({0, 0});
    OS.insert({1e9, 1e9});

    std::vector<int> V(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> V[i];
        OS.insert({V[i], i});
    }


    for (int i = 0; i < Q; i++) {
        char c; std::cin >> c;
        int a, b; std::cin >> a >> b;

        if (c == '?') {
            ordered_set<std::pair<int, int>>::iterator it1 = OS.lower_bound({a, 0});
            ordered_set<std::pair<int, int>>::iterator it2 = OS.upper_bound({b, N});
            std::cout << OS.order_of_key(*it2) - OS.order_of_key(*it1) << '\n';
        } else {
            OS.erase({V[a-1], a-1});
            V[a-1] = b;
            OS.insert({V[a-1], a-1});
        }
    }
}
