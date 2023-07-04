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

    int N; std::cin >> N;

    std::vector<std::array<int, 3>> V(N);
    for (int i = 0; i < N; i++) {
        std::cin >> V[i][0] >> V[i][1];
        V[i][2] = i;
    }

    std::sort(V.begin(), V.end(), [](std::array<int, 3> a, std::array<int, 3> b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });

    std::vector<int> IC(N), CI(N);
    ordered_set<std::array<int, 2>> OIC, OCI;

    for (int i = 0; i < N; i++) {
        OCI.insert({V[i][1], -i});
        CI[V[i][2]] = OCI.size() - OCI.order_of_key({V[i][1], -i}) - 1;
    }
    for (int i = N-1; i >= 0; i--) {
        OIC.insert({V[i][1], -i});
        IC[V[i][2]] = OIC.order_of_key({V[i][1], -i});
    }

    for (int &i : IC) std::cout << i << " ";
    std::cout << "\n";
    for (int &i : CI) std::cout << i << " ";
    std::cout << "\n";
}
