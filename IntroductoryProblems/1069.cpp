#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  int mnum = 0, num = 1;
  if (s.size() == 1) {
    cout << 1 << endl;
    return 0;
  }
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == s[i-1]) {
      num += 1;
    } else {
      num = 1;
    }
    mnum = max(mnum, num);
  }
  cout << mnum << endl;
}
