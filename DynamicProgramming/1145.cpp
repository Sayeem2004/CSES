#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n; cin >> n;
    set<ll> S;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        auto it = S.lower_bound(x);
        if (it == S.end()) S.insert(x);
        else {
            S.erase(it);
            S.insert(x);
        }

  }
  cout << S.size() << "\n";
}
