#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int n;
int ST[400000];

void build() {
    for (int i = n - 1; i > 0; --i)
        ST[i] = max(ST[i<<1],ST[i<<1|1]);
}

void updatevalue(int p, int value) {
    for (ST[p += n] = value; p > 1; p >>= 1)
        ST[p>>1] = max(ST[p],ST[p^1]);
}

int getrange(int l, int r) {
    int res = -1e9;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = max(res,ST[l++]);
        if (r&1) res = max(res,ST[--r]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int q; cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> ST[n+i];
    build();
    for (int i = 0; i < q; i++) {
        int x; cin >> x;
        int l = 0, r = n-1;
        bool br = false;
        while (l < r) {
            int m = (l+r)/2;
            int m1 = getrange(l,m+1);
            int m2 = getrange(m,r+1);
            if (m1 < x && m2 < x) {
                break;
            }
            if (m1 >= x) r = m;
            else if (m2 >= x) l = m+1;
        }
        if (ST[(l+r)/2+n] < x) cout << 0 << " ";
        else {
            cout << (l+r)/2+1 << " ";
            updatevalue((l+r)/2,ST[(l+r)/2+n]-x);
        }
    }
}
