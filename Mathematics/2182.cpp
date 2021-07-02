#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define arr array
ll MOD = 1e9 + 7;
vector<arr<ll,2>> P(100001);

// Binary Exponentiation
ll modpow(ll x, ll n) {
    if (n == 0) return 1 % MOD;
    ll u = modpow(x, n/2);
    u = (u * u) % MOD;
    if (n % 2 == 1) u = (u * x) % MOD;
    return u;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	ll n; cin >> n;
	for (int i = 0; i < n; i++) {
	    ll a, b; cin >> a >> b;
	    P[i] = {a,b};
	}
	ll num = 1, sum = 1, prod = 1, snum = 1;
	for (int i = 0; i < n; i++) {
		num = num * (P[i][1]+1) % MOD;
	    sum = sum * (modpow(P[i][0], P[i][1]+1) - 1) % MOD * modpow(P[i][0]-1, MOD-2) % MOD;
		prod = modpow(prod, P[i][1]+1) * modpow(modpow(P[i][0], (P[i][1]*(P[i][1]+1)/2)), snum) % MOD;
		snum = snum * (P[i][1]+1) % (MOD-1);
	}
	cout << num << " " << sum << " " << prod;
}
