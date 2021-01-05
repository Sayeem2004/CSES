#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
int n;  // array size
int t[400000];

void build() {  // build the tree
    for (int i = n - 1; i > 0; --i)
        t[i] = min(t[i<<1],t[i<<1|1]);
}

void update(int p, int value) {  // update value at position p
    for (t[p += n] = value; p > 1; p >>= 1)
        t[p>>1] = min(t[p],t[p^1]);
}

int get(int l, int r) {  // get on interval [l, r)
    int res = 1e9;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = min(res,t[l++]);
        if (r&1) res = min(res,t[--r]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int q; cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> t[n+i];
    build();
    for (int i = 0; i < q; i++) {
        int x; cin >> x;
        if (x == 2) {
            int y, z; cin >> y >> z;
            cout << get(y-1,z) << "\n";
        } else {
            int y, z; cin >> y >> z;
            update(y-1,z);
        }
    }
}
