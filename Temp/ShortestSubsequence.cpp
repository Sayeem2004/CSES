#include <bits/stdc++.h>
using namespace std;

#define itos(x) to_string(x)
#define stoi(x) stoi(x)
#define ctoi(x) (x-'0')

#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) (int)(x).size()

#define ll long long
#define ld long double
const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ld pi = acos((ld)-1);
const ld e = exp(1);

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  multiset<char> s1;
  for (auto c : s) {
    s1.insert(c);
  }
  set<char> s2;
  for (auto c : s1) {
    s2.insert(c);
  }
  int m = 10000000;
  char e = 'Z';
  for (auto c : s2) {
    int o = s1.count(c);
    if (min(m, o) == o) {
      m = s1.count(c);
      e = c;
    }
  }
  for (int i = 0; i <= m; i++) {
    cout << e;
  }
}
