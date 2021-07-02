#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Set.find_by_order(index)
// Set.order_of_key(number)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    ordered_set<int> OS;
    vector<int> V(n);
    for (int i = 0; i < n; i++) {
        cin >> V[i];
        OS.insert(i);
    }
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        auto itr = OS.find_by_order(a-1);
        cout << V[*itr] << " ";
        OS.erase(itr);
    }
}
