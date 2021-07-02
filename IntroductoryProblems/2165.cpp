#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int countMoves(int n) {
    if (n == 1) return 1;
    return countMoves(n-1)*2+1;
}

void printMoves(int n, int s1, int s2) {
    if (n == 1) {
        cout << s1 << " " << s2 << "\n";
    } else {
        printMoves(n-1,s1,6-(s1+s2));
        cout << s1 << " " << s2 << "\n";
        printMoves(n-1,6-(s1+s2),s2);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    cout << countMoves(n) << "\n";
    printMoves(n, 1, 3);
}
