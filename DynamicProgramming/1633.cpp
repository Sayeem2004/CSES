#include <bits/stdc++.h>
#define ll long long
#define mod(x) (x % 1000000007)

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<ll> count(n + 1);
  count[0] = 1;
  for (int x = 1; x <= n; x++) {
    for (int c = 1; c <= 6; c++) {
      if (x - c >= 0) {
        count[x] += count[x-c];
        count[x] = mod(count[x]);
      }
    }
  }
  cout << count[n] << "\n";
}
