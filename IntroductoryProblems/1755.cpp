#include <bits/stdc++.h>
using namespace std;

#define itos(x) to_string(x)
#define stoi(x) stoi(x)
#define ctoi(x) (x-'0')

#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).end(),(x).begin()
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
  unordered_map<char, int> lettercount;
  for (int i = 0; i < sz(s); i++) {
    lettercount[s[i]]++;
  }
  int odd = 0;
  char oddchar;
  for (auto c : lettercount) {
    if (c.second % 2 == 1) {
      odd++;
    }
  }
  if (odd > 1) {
    cout << "NO SOLUTION" << "\n";
    return 0;
  }
  string a = "", b = "", mid = "";
  for (auto c : lettercount) {
    if (c.second % 2 == 0) {
      string temp(c.second / 2, c.first);
      a = a + temp;
      b = temp + b;
    }
    if (c.second % 2 == 1) {
      string temp(c.second, c.first);
      mid = temp;
    }
  }
  cout << a << mid << b << "\n";
}
