#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
vector<vector<ll>> A(200000);
vector<ll> C(200000), T(200000);
ll n;

void dfs(ll v, ll p, ll d) {
    T[0] += d;
    C[v] = 1;
    for (auto x : A[v]) {
        if (x == p) continue;
        dfs(x, v, d+1);
        C[v] += C[x];
    }
}

void dfs(ll v, ll p) {
    for (auto x : A[v]) {
        if (x == p) continue;
        T[x] = T[v] + n - 2 * C[x];
        dfs(x, v);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        ll a, b; cin >> a >> b;
        A[a-1].push_back(b-1);
        A[b-1].push_back(a-1);
    }
    dfs(0, -1, 0);
    dfs(0, -1);
    for (int i = 0; i < n; i++)
        cout << T[i] << " ";
    cout << "\n";
}
