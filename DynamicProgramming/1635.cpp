#include <bits/stdc++.h>
#define ll long long
#define mod(x) (x % 1000000007)

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  vector<int> coins;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    coins.push_back(a);
  }
  vector<ll> count(x+1);
  count[0] = 1;
  for (int i = 1; i <= x; i++) {
    for (auto c : coins) {
      if (i - c >= 0) {
        count[i] += count[i-c];
        count[i] = mod(count[i]);
      }
    }
  }
  cout << count[x] << "\n";
}
