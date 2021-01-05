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

vector<vector<int>> room;
int n, m;

void rmap(int x, int y) {
  if (room[x][y] == 0) {
    room[x][y] = 1;
    if (x < n-1) rmap(x+1,y);
    if (x > 0) rmap(x-1,y);
    if (y < m-1) rmap(x,y+1);
    if (y > 0) rmap(x,y-1);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> n >> m;
  vector<vector<int>> v(n);
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    vector<int> temp(m);
    for (int q = 0; q < m; q++) {
      if (s[q] == '#') temp[q] = 1;
      else temp[q] = 0;
    }
    v[i] = temp;
  }
  room = v;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int q = 0; q < m; q++) {
      if (room[i][q] == 0) {
        ans++;
        rmap(i,q);
      }
    }
  }
  cout << ans << "\n";
}
