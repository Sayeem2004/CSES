#include <bits/stdc++.h>
#define ll long long

using namespace std;

multiset<int> pf(int n) {
  multiset<int> f;
  for (int x = 2; x * x <= n; x++) {
    while (n % x == 0) {
      f.insert(x);
      n /= x;
    }
  }
  if (n > 1) {
    f.insert(n);
  }
  return f;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int y;
    cin >> y;
    multiset<int> p = pf(y);
    set<int> p2;
    for (auto q : p) {
      p2.insert(q);
    }
    int ans = 1;
    for (auto c : p2) {
      ans *= (p.count(c) + 1);
    }
    cout << ans << "\n";
  }
}
