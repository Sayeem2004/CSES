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
  vector<pair<ll,ll>> v(n*2);
  for (int i = 0; i < n*2; i++) {
    int x; cin >> x;
    if (i%2 == 0) v[i] = make_pair(x,1);
    else v[i] = make_pair(x,-1);
  }
  sort(all(v));
  int ans = 0, curr = 0;
  for (int i = 0; i < n*2; i++) {
    curr += v[i].second;
    ans = max(ans,curr);
  }
  cout << ans << "\n";
}
