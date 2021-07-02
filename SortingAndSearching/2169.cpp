#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ll int64_t
#define F first
#define S second
template <typename T> using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Set.find_by_order(index)
// Set.order_of_key(number)

bool comp(pair<int,int> a, pair<int,int> b){
    if (a.F < b.F) {
        return true;
    } else if (a.F == b.F && a.S > b.S){
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<pair<int,int>> V(n), S(n);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        V[i] = {a,b};
        S[i] = {a,b};
    }
    sort(S.begin(),S.end(),comp);
    map<pair<int,int>, int> P;
    for (int i = 0; i < n; i++) {
        P[S[i]] = i;
    }
    vector<int> I(n), O(n);
    ordered_set<pair<int,int>> OS;
    for (int i = 0; i < n; i++) {
        OS.insert({S[i].S,n-i-1});
        I[i] = i - OS.order_of_key({S[i].S,n-i-1});
    }
    OS.clear();
    for (int i = n-1; i >= 0; i--) {
        OS.insert({S[i].S,n-i-1});
        O[i] = OS.order_of_key({S[i].S,n-i-1});
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
