#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, k; cin >> n >> k;
    vector<ll> V(n);
    for (int i = 0; i < n; i++)
        cin >> V[i];
    ll sm = 0, l = 0, r = 0;
    map<ll,ll> M;
    while (r < n) {
        M[V[r]]++;
        while (M.size() > k) {
            M[V[l]]--;
            if (M[V[l]] == 0) M.erase(V[l]);
            l++;
        }
        sm += r-l+1;
        r++;
    }
    cout << sm << "\n";
}
