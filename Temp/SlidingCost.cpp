#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll int64_t
typedef tree<int, null_type,
             less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    Ordered_set;

int main() {
    int n, k; cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Ordered_set s;
    for (int i = 0; i < k; i++)
        s.insert(arr[i]);
    ll ans = 0;
    int median = *s.find_by_order(k/2+k%2-1);
    for (int i = 0; i < k; i++)
        ans += abs(arr[i]-median);
    cout << ans << " ";
    for (int i = 0; i < n - k; i++) {
        s.erase(s.find_by_order(s.order_of_key(arr[i])));
        s.insert(arr[i+k]);
        ans = 0;
        median = *s.find_by_order(k/2+k%2-1);
        for (int q = i+1; q <= i+k; q++)
            ans += abs(arr[q]-median);
        cout << ans << " ";
    }
    cout << "\n";
}
