#include <bits/stdc++.h>
#define ll long long
#define mod(x) (x % 1000000007)
#define itos(x) (to_string(x))
#define stoi(x) (stoi(x))
#define ctoi(x) (x-'0')

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> count(n+1, 10000000);
  count[n] = 0;
  for (int i = n; i >= 0; i--) {
    if (count[i] != 10000000) {
      string x = itos(i);
      for (int c : x) {
        c -= 48;
        count[i-c] = min(count[i-c],count[i]+1);
      }
    }
  }
  cout << count[0] << "\n";
}
