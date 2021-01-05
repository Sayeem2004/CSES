#include <iostream>
#define ll long long

using namespace std;

int main() {
  ll n;
  cin >> n;
  ll sum = 0;
  for(int i = 1; i < n; i++) {
    ll a;
    cin >> a;
    sum += a;
  }
  ll out = (n + 1) * n / 2;
  out -= sum;
  cout << out;
}
