#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int bin(string s) {
    reverse(s.begin(),s.end());
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        ans += (s[i] == '1') << i;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    vector<int> V(n);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        V[i] = bin(s);
    }
    int ans = 100;
    for (int i = 0; i < n; i++) {
        for (int q = i+1; q < n; q++) {
            ans = min(ans, (int)__builtin_popcount(V[i]^V[q]));
        }
    }
    cout << ans << "\n";
}
