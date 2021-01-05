#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

ll getMid(ll s, ll e) {
    return s + (e-s)/2;
}
ll constructSTUtil(ll arr[], ll ss, ll se, ll *st, ll si) {
    if (ss == se) {
        st[si] = arr[ss];
        return arr[ss];
    }
    ll mid = getMid(ss,se);
    st[si] = constructSTUtil(arr,ss,mid,st,si*2+1) ^ constructSTUtil(arr,mid+1,se,st,si*2+2);
    return st[si];
}
ll *constructST(ll arr[], ll n) {
    ll x = (ll)(ceil(log2(n)));
    ll max_size = 2*(ll)pow(2, x) - 1;
    ll *st = new ll[max_size];
    constructSTUtil(arr, 0, n-1, st, 0);
    return st;
}

ll getValueUtil(ll *st, ll ss, ll se, ll qs, ll qe, ll si) {
    if (qs <= ss && qe >= se)
        return st[si];
    if (se < qs || ss > qe)
        return 0;
    ll mid = getMid(ss,se);
    return getValueUtil(st,ss,mid,qs,qe,2*si+1) ^ getValueUtil(st,mid+1,se,qs,qe,2*si+2);
}
ll getValue(ll *st, ll n, ll qs, ll qe) {
    if (qs < 0 || qe > n-1 || qs > qe) {
        cout << "Invalid Input" << "\n";
        return -1;
    }
    return getValueUtil(st,0,n-1,qs,qe,0);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    ll v[n];
    for (int i = 0; i < n; i++)
        cin >> v[i];
    ll *st = constructST(v,n);
    for (int i = 0; i < q; i++) {
		ll x, y; cin >> x >> y;
        cout << getValue(st,n,x-1,y-1) << "\n";
    }
}
