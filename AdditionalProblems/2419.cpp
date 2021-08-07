#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

// function to change bases
string cbase(ll n, ll b) {
    string s = "";
    vector<char> c = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
    while (n > 0) {
        s = c[n%b]+s;
        n = n/b;
    }
    return s;
}

// return true if nCp is odd, else false
bool check(ll n, ll p) {
    string sn = cbase(n, 2);
    string sp = cbase(p, 2);
    reverse(sn.begin(),sn.end());
    reverse(sp.begin(),sp.end());
    for (int i = 0; i < min(sp.size(),sn.size()); i++) {
        if (sn[i] == '0' && sp[i] == '1')
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> V(n);
    for (int i = 0; i < n; i++)
        cin >> V[i];
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (check(n-1, i)) ans ^= V[i];
    }
    cout << (ans^1) << "\n";
}
