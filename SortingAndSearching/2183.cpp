#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vector<ll> V(n);
    for (int i = 0; i < n; i++) {
        cin >> V[i];
    }
    sort(V.begin(),V.end());
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        if (ans < V[i]) {
            cout << ans << "\n";
            return 0;
        } else {
            ans += V[i];
        }
    }
    cout << ans << "\n";
}
