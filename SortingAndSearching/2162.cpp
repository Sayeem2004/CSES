#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

// Set.find_by_order(index)
// Set.find_by_key(number)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    ordered_set S;
    for (int i = 1; i <= n; i++) {
        S.insert(i);
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
        index = ((index + 1) % S.size());
        int c = *S.find_by_order(index);
        cout << c << " ";
        S.erase(c);
    }
}
