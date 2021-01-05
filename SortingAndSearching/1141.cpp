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
  map<int,int> m;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    m[v[i]] = -1;
  }
  int count = 0, i = 0, j = 0;
  while (j < n) {
    if (m[v[j]] >= i) {
      i = m[v[j]]+1;
    }
    m[v[j]] = j;
    count = max(count,j-i+1);
    j++;
  }
  cout << count << "\n";
}
