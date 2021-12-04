#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

// Change Base
string cbase(ll n, ll b) {
    string s = "";
    vector<char> c = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    while (n > 0) {
        s = c[n%b]+s;
        n = n/b;
    }
    return s;
}

// Highest Power Of 2 That Divides N
ll div2(ll n) {
    return (n & (~(n-1)));
}

// Binary Exponentiation
ll modpow(ll x, ll n, ll m) {
    if (n == 0) return 1 % m;
    ll u = modpow(x, n/2, m);
    u = (u * u) % m;
    if (n % 2 == 1) u = (u * x) % m;
    return u;
}

// Prime Factorization of an integer
vector<ll> pfactor(ll n) {
    vector<ll> f;
    while (n % 2 == 0) {
        f.pb(2);
        n /= 2;
    }
    for (ll x = 3; x*x <= n; x += 2) {
        while (n%x == 0) {
            f.pb(x);
            n /= x;
        }
    }
    if (n > 1) f.pb(n);
    return f;
}

// Prime or Composite
bool prime(ll n) {
    if (n < 2) return false;
    if (n == 2 || n == 3 || n == 5 || n == 7) return true;
    if (n % 2 == 0) return false;
    for (ll x = 3; x*x <= n; x += 2) {
        if (n % x == 0) return false;
    }
    return true;
}

// Sieve of Eratosthenes
vector<ll> sieve(ll a, ll b) {
    vector<ll> v(b+1);
    for (ll x = 2; x <= b; x++) {
        if (v[x]) continue;
        for (ll u = 2 * x; u <= b; u += x) v[u] = x;
    }
    vector<ll> ans = {v.begin()+a, v.end()};
    return ans;
}
