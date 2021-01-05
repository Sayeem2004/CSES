#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, k; cin >> n >> k;
    vector<ll> v(n);
    ll mx = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        mx = max(x,mx);
        sum += x;
        v[i] = x;
    }
    ll start = mx, end = 1e18, mid;
    if (k == 1) {
        cout << sum << "\n";
        return 0;
    }
    while (start <= end) {
        mid = (start+end)/2;
        ll count = 1, curr = 0;
        for (int i = 0; i < n; i++) {
            if (curr + v[i] > mid) {
                curr = v[i];
                count++;
            } else {
                curr += v[i];
            }
        }
        if(count <= k) {
            end = mid-1;
        } else {
            start = mid+1;
        }
    }
    ll ans = mid, count, curr;
    count = 1, curr = 0;
    for (int i = 0; i < n; i++) {
        if (curr + v[i] > mid+1) {
            curr = v[i];
            count++;
        } else {
            curr += v[i];
        }
    }
    if (count == k && mx <= mid+1) ans = mid+1;
    count = 1, curr = 0;
    for (int i = 0; i < n; i++) {
        if (curr + v[i] > mid) {
            curr = v[i];
            count++;
        } else {
            curr += v[i];
        }
    }
    if (count == k && mx <= mid) ans = mid;
    count = 1, curr = 0;
    for (int i = 0; i < n; i++) {
        if (curr + v[i] > mid-1) {
            curr = v[i];
            count++;
        } else {
            curr += v[i];
        }
    }
    if (count == k && mx <= mid-1) ans = mid-1;
    cout << ans << "\n";
}
