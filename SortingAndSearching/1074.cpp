#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  ll median = 0, ans = 0;
  vector<ll> v;
  for (ll i = 0; i < n; i++) {
    ll a;
    cin >> a;
    v.push_back(a);
  }
  int q = v.size();
  sort(v.begin(),v.end());
  if (q % 2 == 1) {
    median = v[(q-1)/2];
  } else {
    median = (v[q/2] + v[q/2-1]) / 2;
  }
  for (auto x : v) {
    ans += abs(median - x);
  }
  cout << ans << "\n";
}
