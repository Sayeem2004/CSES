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
  vector<int> v(n);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    mx = max(mx,v[i]);
  }
  vector<int> div(mx+1,0);
  for (auto x : v) div[x]++;
  int ans = 1;
  for (int i = mx; i >= 1; i--) {
    int j = i, counter = 0;
    bool br = false;
    while (j <= mx) {
      if (div[j] >= 2) {
        ans = i; br = true; break;
      } else if (div[j] == 1) {
        counter++;
      }
      if (counter == 2 && j <= mx) {
        ans = i; br = true; break;
      }
      j += i;
    }
    if (br) break;
  }
  cout << ans << "\n";
}
