#include <bits/stdc++.h>
#define ll long long
#define mod(x) (x % 1000000007)

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> s1, s2;
  if (n % 4 == 0) {
    for (int i = 1; i <= n; i++) {
      if (i % 4 == 1 || i % 4 == 0) {
        s1.push_back(i);
      } else if (i % 4 == 2 || i % 4 == 3) {
        s2.push_back(i);
      }
    }
    cout << "YES" << "\n";
    cout << n / 2 << "\n";
    for (auto c : s1) {
      cout << c << " ";
    }
    cout << "\n";
    cout << n / 2 << "\n";
    for (auto c : s2) {
      cout << c << " ";
    }
    cout << "\n";
    return 0;
  } else if (n % 4 == 3) {
    for (int i = 4; i <= n; i++) {
      if (i % 4 == 0 || i % 4 == 3) {
        s1.push_back(i);
      } else if (i % 4 == 1 || i % 4 == 2) {
        s2.push_back(i);
      }
    }
    cout << "YES" << "\n";
    cout << n / 2 + 1 << "\n";
    cout << 1 << " " << 2 << " ";
    for (auto c : s1) {
      cout << c << " ";
    }
    cout << "\n";
    cout << n / 2  << "\n";
    cout << 3 << " ";
    for (auto c : s2) {
      cout << c << " ";
    }
    cout << "\n";
    return 0;
  }
  cout << "NO" << "\n";
}
