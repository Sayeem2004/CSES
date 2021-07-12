#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define arr array

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, x; cin >> n >> x;
    vector<arr<int,2>> V(n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        V[i] = {a, i};
    }
    sort(V.begin(), V.end());
    int a = 0, b = n-1;
    int br = true;
    while (a < b) {
        if (V[a][0] + V[b][0] == x) {
            cout << V[a][1]+1 << " " << V[b][1]+1 << "\n";
            br = false; break;
        }
        if (V[a][0] + V[b][0] < x) {
            a++; continue;
        }
        if (V[a][0] + V[b][0] > x) {
            b--; continue;
        }
    }
    if (br) cout << "IMPOSSIBLE\n";
}
