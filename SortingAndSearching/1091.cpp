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
  int n, m; cin >> n >> m;
  set<array<int,2>> s;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    s.insert({x,i});
  }
  for (int i = 0; i < m; i++) {
    int x; cin >> x;
    auto itr = s.lower_bound({x+1,0});
    if (itr == s.begin()) cout << -1 << "\n";
    else {
      itr--; int y = (*itr)[0];
      cout << y << "\n";
      s.erase(itr);
    }
  }
}
