#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define arr array

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    vector<arr<int,2>> V(n);
    for (int i = 0; i < n; i++)
        cin >> V[i][1] >> V[i][0];
    sort(V.begin(),V.end());
    multiset<int> P;
    for (int i = 0; i < k; i++)
        P.insert(0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto itr = P.lower_bound(V[i][1]+1);
        if (itr != P.begin()) itr--;
        if (*itr <= V[i][1]) {
            ans++;
            P.erase(itr);
            P.insert(V[i][0]);
        }
    }
    cout << ans << "\n";
}
