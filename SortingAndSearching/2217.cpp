#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define arr array

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> V(n+2), POS(n+2);
    V[0] = 0; POS[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> V[i];
        POS[V[i]] = i;
    }
    V[n+1] = n+1; POS[n+1] = n+1;
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (POS[i] > POS[i+1]) ans++;
    }
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        set<arr<int,2>> S;
        S.insert({V[a]-1,V[a]});
        S.insert({V[a],V[a]+1});
        S.insert({V[b]-1,V[b]});
        S.insert({V[b],V[b]+1});
        int curr = ans;
        for (auto x : S) {
            int p1 = POS[x[0]], p2 = POS[x[1]];
            int np1, np2;
            if (x[0] == V[a]) np1 = b;
            else if (x[0] == V[b]) np1 = a;
            else np1 = p1;
            if (x[1] == V[a]) np2 = b;
            else if (x[1] == V[b]) np2 = a;
            else np2 = p2;
            if (p1 > p2 && np1 < np2) curr--;
            if (p1 < p2 && np1 > np2) curr++;
        }
        cout << curr << "\n";
        ans = curr;
        POS[V[a]] = b; POS[V[b]] = a;
        int t = V[a]; V[a] = V[b]; V[b] = t;
    }
}
    
