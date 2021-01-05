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

vector<ll> v;

ll mindif(ll i, ll subsum, ll sum) {
  if (i == 0) {
    ll a = sum-subsum;
    return llabs(a-subsum);
  }
  ll b = min(mindif(i-1,subsum+v[i-1],sum),mindif(i-1,subsum,sum));
  return b;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n; cin >> n;
  ll sum = 0;
  for (ll q = 0; q < n; q++) {
    ll x; cin >> x;
    v.pb(x);
    sum += x;
  }
  cout << mindif(n, 0, sum) << "\n";
}
