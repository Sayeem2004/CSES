#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, a, b; cin >> n >> a >> b;
    vector<ll> P(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> P[i];
        P[i] += P[i-1];
    }
    multiset<ll> MS;
    ll ans = -1e18;
    for(int i=a; i <= n; i++) {
        if (i > b) MS.erase(MS.find(P[i-b-1]));
        MS.insert(P[i-a]);
        ans = max(ans, P[i]-*(MS.begin()));
    }
    cout << ans << "\n";
}
