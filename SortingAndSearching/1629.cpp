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
  int n; cin >> n;
  vector<pair<int,int>> v(n);
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    v[i] = make_pair(y,x);
  }
  sort(all(v));
  int i = 1, prev = v[0].first, count = 1;
  while (i < n) {
    if (v[i].second >= prev) {
      count++;
      prev = v[i].first;
      continue;
    }
    i++;
  }
  cout << count << "\n";
}
