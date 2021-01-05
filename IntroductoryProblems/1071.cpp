#include <iostream>
#define ll long long

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    ll row, col;
    cin >> row >> col;
    ll num = 0;
    if (row > col) {
      if (row % 2 == 0) {
        num = row * row - col + 1;
      } else {
        num = (row - 1) * (row - 1) + col;
      }
    } else if (col > row) {
      if (col % 2 == 1) {
        num = col * col - row + 1;
      } else {
        num = (col - 1) * (col - 1) + row;
      }
    } else {
      if (row % 2 == 0) {
        num = row * row - col + 1;
      } else {
        num = col * col - row + 1;
      }
    }
    cout << num << endl;
  }
}
