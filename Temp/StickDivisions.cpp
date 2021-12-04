#include <bits/stdc++.h>
using namespace std;
#define int64 int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int64 x, n; cin >> x >> n;
    vector<int64> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.rbegin(),v.rend());
    int64 ans = 0;
    for (int i = 0; i < n; i++) {
        if (i != n-1) ans += x;
        x -= v[i];
    }
    cout << ans << "\n";
}
