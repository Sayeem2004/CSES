#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vect;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    vect.push_back(a);
  }
  ll num = 0;
  for (int i = 1; i < n; i++) {
    if (vect[i] < vect[i-1]) {
      num += (vect[i-1] - vect[i]);
      vect[i] += (vect[i-1] - vect[i]);
    }
  }
  cout << num << endl;
}
