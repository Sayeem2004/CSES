#include <bits/stdc++.h>
using namespace std;
#define int64 int64_t

// Binary Exponentiation
int64 modpow(int64 x, int64 n) {
    if (n == 0) return 1;
    int64 u = modpow(x, n/2);
    u = (u * u);
    if (n % 2 == 1) u = (u * x) ;
    return u;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int64 n; cin >> n;
    int64 ans = 0;
    for (int64 i = 0; i <= log2(n); i++) {
        int64 div = modpow(2,i);
        int64 count = (n+1)/div;
        if (count%2 == 0) {
            ans += count*div/2;
        } else {
            ans += (n+1)%div;
            count--;
            ans += count*div/2;
        }
    }
    cout << ans << "\n";
}
