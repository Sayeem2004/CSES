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

void fact() {
    FN[0] = FN[1] = 1;
    for (int i = 2; i <= maxn; i++)
        FN[i] = (FN[i-1] * i) % mod;
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

}
