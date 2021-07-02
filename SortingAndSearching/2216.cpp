#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> V(n), POS(n);
    for (int i = 0; i < n; i++) {
        cin >> V[i];
        POS[V[i]-1] = i;
    }
    int ans = 1;
    for (int i = 0; i < n-1; i++) {
        if (POS[i] > POS[i+1]) ans++;
    }
    cout << ans << "\n";
}
