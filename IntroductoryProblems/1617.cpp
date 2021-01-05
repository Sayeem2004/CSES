#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  ll out = 1;
  ll mod = pow(10, 9) + 7;
  for (int i = 0; i < n; i++) {
    out *= 2;
    out %= mod;
  }
  cout << out << "\n";
}
