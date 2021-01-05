#include <bits/stdc++.h>
#define ll long long
#define mod(x) (x % 1000000007)

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  vector<string> s1;
  sort (s.begin(),s.end());
  string s2 = s;
  while (next_permutation(s.begin(),s.end())) {
    s1.push_back(s);
  }
  cout << s1.size() + 1 << "\n";
  cout << s2 << "\n";
  for (auto c : s1) {
    cout << c << "\n";
  }
}
