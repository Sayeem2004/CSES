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

int ans = 0;
bool column[8], diag1[64], diag2[64];
set<pair<int,int>> trap;

void solve(int y) {
  if (y == 8) { ans++; return; }
  for (int x = 0; x < 8; x++) {
    if (column[x] || diag1[x+y] || diag2[x-y+8-1]) continue;
    if (trap.find(make_pair(x,y)) != trap.end()) continue;
    column[x] = diag1[x+y] = diag2[x-y+8-1] = true;
    solve(y+1);
    column[x] = diag1[x+y] = diag2[x-y+8-1] = false;
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  for (int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      char x; cin >> x;
      if (x == '*') {
        trap.insert(make_pair(i,j));
      }
    }
  }
  solve(0);
  cout << ans << "\n";
}
