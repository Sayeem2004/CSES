#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

vector<ll> subset(vector<ll> a) {
    vector<ll> s;
    for (int b = 0; b < (1<<a.size()); b++) {
        ll sum = 0;
        for (int i = 0; i < a.size(); i++) {
            if (b&(1<<i)) sum += a[i];
        }
        s.push_back(sum);
    }
    return s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, sum; cin >> n >> sum;
    vector<ll> A1(n/2), A2(n-n/2);
    for (int i = 0; i < n/2; i++) cin >> A1[i];
    for (int i = 0; i < n-n/2; i++) cin >> A2[i];
    vector<ll> S1 = subset(A1);
    vector<ll> S2 = subset(A2);
    ll ans = 0;
    sort(S2.begin(),S2.end());
    for (auto x : S1) {
        auto itr1 = upper_bound(S2.begin(),S2.end(),sum-x);
        auto itr2 = lower_bound(S2.begin(),S2.end(),sum-x);
        ans += itr1-itr2;
    }
    cout << ans << '\n';
}
