#include <bits/stdc++.h>
using namespace std;

#define lltos(x) to_string(x)
#define stoll(x) stoll(x)
#define ctoi(x) (x-'0')
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;
const ld pi = acos((ld)-1);
const ld e = exp(1);

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int n, k; cin >> n >> k;
  vector<int> v(n),s(n);
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    v[i] = x;
    s[i] = x;
  }
  sort(all(s));
  int a = 0, b = n-1;
  bool found = false;
  while (a < b) {
    if (s[a]+s[b] == k) {
      found = true; break;
    }
    if (s[a]+s[b] > k) b--;
    if (s[a]+s[b] < k) a++;
  }
  if (found) {
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
      if (v[i] == s[a] && x == 0) x = i;
      if (v[i] == s[b] && x != i) y = i;
      if (x != 0 && y != 0) break;
    }
    cout << x+1 << " " << y+1 << "\n";
  } else {
    cout << "IMPOSSIBLE" << "\n";
  }
}
