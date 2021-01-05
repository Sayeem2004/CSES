#include <iostream>
#include <math.h>
#define ll long long

using namespace std;

int main() {
  ll n;
  cin >> n;
  int sum = 0;
  for(int i = 1; i < 100; i++) {
    sum += floor(n / pow(5,i));
  }
  cout << sum;
}
