#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int maxn = 1000000;
int mod = 1000000007;
vector<ll> FN(maxn+1), FI(maxn+1), NI(maxn+1), DR(maxn+1);

void inv() {
    NI[0] = NI[1] = 1;
    for (int i = 2; i <= maxn; i++)
        NI[i] = (NI[mod%i] * (mod-mod/i)) % mod;
}

void finv() {
    FI[0] = FI[1] = 1;
    for (int i = 2; i <= maxn; i++)
        FI[i] = (NI[i] * FI[i-1]) % mod;
}

void fact(int spec) {
    FN[0] = FN[1] = 1;
    for (int i = 2; i <= maxn; i++) {
        if (i == spec) FN[i] = FN[i-1];
        else FN[i] = (FN[i-1] * i) % mod;
    }
}

void derang() {
    DR[0] = 1; DR[1] = 0;
    for (int i = 2; i <= maxn; i++)
        DR[i] = (DR[i-1]+DR[i-2]) * (i-1) % mod;
}

ll nCr(ll n, ll r) {
    ll ans = FN[n] * FI[r] % mod * FI[n-r] % mod;
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t; cin >> t;
    if (t % 2 == 1) {
        cout << 0 << "\n";
        return 0;
    }
    string s; cin >> s;
    ll k = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') k++;
        else k--;
        if (k < 0 || k > t/2) {
            cout << 0 << "\n";
            return 0;
        }
    }
    ll n = (t-s.size()-k)/2;
    if (n == 0) {
        cout << 1 << "\n";
        return 0;
    }
    inv(); finv(); fact(n+k+1);
    cout << ((k+1) * nCr(2*n+k, n)) % mod << "\n";
}
