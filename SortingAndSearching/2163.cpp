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

    ordered_set<int> OS;
    for (int i = 1; i <= N; i++) OS.insert(i);

    int pos = 0;
    while (!OS.empty()) {
        pos = (pos + K) % OS.size();
        ordered_set<int>::iterator it = OS.find_by_order(pos);

        std::cout << *it << " ";
        OS.erase(it);
    }

    std::cout << "\n";
}
