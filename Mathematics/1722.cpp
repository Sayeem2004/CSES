#include <bits/stdc++.h>
using namespace std;
#define int64 int64_t

void multiply(int64 F[2][2], int64 M[2][2]) {
    int64 x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int64 y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int64 z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int64 w = F[1][0] * M[0][1] + F[1][1] * M[1][1];
    x %= (int64)1e9+7;
    y %= (int64)1e9+7;
    z %= (int64)1e9+7;
    w %= (int64)1e9+7;
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void power(int64 F[2][2], int64 n) {
    if (n == 0 || n == 1) return;
    int64 M[2][2] = {{1, 1}, {1, 0}};
    power(F, n/2);
    multiply(F, F);
    if (n % 2 != 0) multiply(F, M);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int64 n; cin >> n;
    int64 F[2][2] = {{1, 1}, {1, 0}};
    if (n == 0) {
        cout << 0 << "\n"; return 0;
    }
    power(F, n-1);
    cout << F[0][0] << "\n";
}
