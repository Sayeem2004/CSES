#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<ll> v;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    v.push_back(x);
  }
  ll sum = v[0];
  ll best = v[0];
  for (int i = 1; i < n; i++) {
    sum = max(v[i],sum+v[i]);
    best = max(best, sum);
  }
  cout << best << "\n";
}
