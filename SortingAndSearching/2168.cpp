#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define arr array

bool comp(arr<int, 2> a, arr<int,2> b){
    if (a[0] < b[0]) {
        return true;
    } else if (a[0] == b[0] && a[1] > b[1]){
        return true;
    } else {
        return false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<arr<int,2>> V(n), S(n);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        V[i] = {a,b};
        S[i] = {a,b};
    }
    sort(S.begin(),S.end(),comp);
    map<arr<int,2>, int> P;
    for (int i = 0; i < n; i++) {
        P[S[i]] = i;
    }
    vector<int> I(n), O(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (mx >= S[i][1]) I[i] = 1;
        mx = max(mx, S[i][1]);
    }
    int mn = 2000000000;
    for (int i = n-1; i >= 0; i--) {
        if (mn <= S[i][1]) O[i] = 1;
        mn = min(mn, S[i][1]);
    }
    for (int i = 0; i < n; i++) {
        cout << O[P[V[i]]] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << I[P[V[i]]] << " ";
    }
    cout << "\n";
}
