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
    int c;
    cin >> c;
    coins.push_back(c);
  }
  vector<int> count(x + 1);
  count[0] = 0;
  for (int i = 1; i <= x; i++) {
    count[i] = 100000000;
    for (auto c : coins) {
      if (i - c >= 0) {
        count[i] = min(count[i],count[i-c]+1);
      }
    }
  }
  if (count[x] == 100000000) {
    cout << -1 << "\n";
    return 0;
  }
  cout << count[x] << "\n";
}
