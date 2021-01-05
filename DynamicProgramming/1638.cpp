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
  cin.tie(0);
  ll n; cin >> n;
  ll count[n][n];
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    for (ll q = 0; q < n; q++) {
      if (s[q] == '.') count[i][q] = 0;
      else count[i][q] = -1;
    }
  }
  if (count[0][0] == -1 || count[n-1][n-1] == -1) {
    cout << 0 << "\n"; return 0;
  }
  count[0][0] = 1;
  for (ll i = 0; i < n; i++) {
    for (ll q = 0; q < n; q++) {
      if (count[i][q] == -1) continue;
      if (i == 0 && q == 0) continue;
      if (i == 0) count[i][q] = max(0LL,count[i][q-1]) % mod;
      else if (q == 0) count[i][q] = max(0LL,count[i-1][q]) % mod;
      else count[i][q] = (max(0LL,count[i][q-1])+max(0LL,count[i-1][q])) % mod;
    }
  }
  cout << count[n-1][n-1] << "\n";
}
