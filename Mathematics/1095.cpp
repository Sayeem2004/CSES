#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll modpow(int x, int n, int m) {
  if (n == 0) {
    return 1 % m;
  }
  long long u = modpow(x, n/2, m);
  u = (u * u) % m;
  if (n % 2 == 1) {
    u = (u * x) % m;
  }
  return u;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    ll ans = modpow(a, b, 1000000007);
    cout << ans << "\n";
  }
}
