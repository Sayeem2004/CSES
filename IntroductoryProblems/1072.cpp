#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    if (i == 1) {
      cout << 0 << "\n";
    } else if (i == 2) {
      cout << 6 << "\n";
    } else {
      ll total = (pow(i, 4) - pow(i, 2)) / 2;
      ll check = ((i - 1) * 2) * ((i - 2) * 2);
      cout << total - check << "\n";
    }
  }
}
