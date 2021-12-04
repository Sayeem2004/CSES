#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#pragma GCC target("popcnt")

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    bitset<3000> V[n];
    for (int i = 0; i < n; i++)
        cin >> V[i];
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int q = i+1; q < n; q++) {
            ll cnt = (V[i]&V[q]).count();
            ans += cnt*(cnt-1)/2;
        }
    }
    cout << ans << "\n";
}
