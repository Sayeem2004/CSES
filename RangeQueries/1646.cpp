#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, q;
  cin >> n >> q;
  vector<ll> los;
  los.push_back(0);
  ll sum = 0;
  for (ll i = 0; i < n; i++) {
    ll a;
    cin >> a;
    sum += a;
    los.push_back(sum);
  }
  for (ll i = 0; i < q; i++) {
    ll b, c;
    cin >> b >> c;
    cout << los[c] - los[b-1] << "\n";
  }
}
