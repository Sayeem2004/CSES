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
  int n, m, k; cin >> n >> m >> k;
  vector<int> v(n), v2(m);
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 0; i < m; i++) cin >> v2[i];
  sort(all(v)); sort(all(v2));
  int x = 0, y = 0, count = 0;
  while (x < n && y < m) {
    if (abs(v[x]-v2[y]) <= k) {
      count++; x++; y++; continue;
    }
    if (v[x] < v2[y]-k) x++;
    if (v[x] > v2[y]+k) y++;
  }
  cout << count << "\n";
}
