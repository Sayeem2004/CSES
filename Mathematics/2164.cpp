#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

ll jq(ll n,ll k) {
    if (n == 1) return 1;
    if (k <= (n+1)/2) {
        if (2*k == n+1) return 1;
        else return 2*k;
    }
    ll prev = jq(n/2, k-(n+1)/2);
    if (n%2==1) return 2*prev+1;
    return 2*prev-1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) {
        ll n, k; cin >> n >> k;
        cout << jq(n, k) << "\n";
    }
}
