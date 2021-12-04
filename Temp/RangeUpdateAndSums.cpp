#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int n = 4;  // array size
int st[400000];

void build() {  // build the tree
    for (int i = n - 1; i > 0; --i)
        st[i] = st[i<<1] + st[i<<1|1];
}

void update(int p, int value) {  // update at position p
    for (st[p += n] = value; p > 1; p >>= 1)
        st[p>>1] = st[p] + st[p^1];
}

void updaterange(int l, int r, int value) { // update on interval [l,r)
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) st[l++] += value;
        if (r&1) st[--r] += value;
    }
}

int get(int p) { // get at position p
    return st[p+n];
}

int getrange(int l, int r) {  // get on interval [l, r)
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += st[l++];
        if (r&1) res += st[--r];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    st[5] = 1; st[6] = 2; st[7] = 3; st[8] = 4;
    build();
    for (int i = 0; i < 8; i++)
        cout << st[i] << " ";
    cout << "\n";
    updaterange(1,4,15);
    for (int i = 0; i < 8; i++)
        cout << st[i] << " ";
    cout << "\n";
}
