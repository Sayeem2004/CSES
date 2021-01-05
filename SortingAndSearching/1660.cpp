#include <bits/stdc++.h>
using namespace std;
#define ll int64_t


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, sum; cin >> n >> sum;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    set<ll> s;
    ll curr = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        curr += v[i];
        if (curr == sum) ans++;
        ans += s.count(curr-sum);
        s.insert(curr);
    }
    cout << ans << "\n";
}
