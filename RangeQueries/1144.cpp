#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define arr array
int MOD = 1000000007;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Set.find_by_order(index)
// Set.order_of_key(number)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, q; cin >> n >> q;
    vector<ll> V(n);
    ordered_set<arr<ll,2>> OS;
    for (int i = 0; i < n; i++) {
        cin >> V[i];
        OS.insert({V[i], i});
    }
    OS.insert({MOD, 0});
    OS.insert({0, 0});
    for (int i = 0; i < q; i++) {
        char c; cin >> c;
        ll a, b; cin >> a >> b;
        if (c == '?') {
            auto upper = OS.lower_bound({b+1, 0});
            auto lower = OS.lower_bound({a, 0});
            cout << OS.order_of_key(*upper) - OS.order_of_key(*lower) << "\n";
        } else {
            OS.erase({V[a-1],a-1});
            V[a-1] = b;
            OS.insert({V[a-1],a-1});
        }
    }
}
