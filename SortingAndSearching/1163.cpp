#include <bits/stdc++.h>
using namespace std;

#define lltos(x) to_string(x)
#define stoll(x) stoll(x)
#define ctoi(x) (x-'0')
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;
const ld pi = acos((ld)-1);
const ld e = exp(1);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int mx, n; cin >> mx >> n;
    multiset<int> dif; dif.insert(mx);
    set<int> pos; pos.insert(0); pos.insert(mx);
    for (int i = 0; i < n; i++) {
        int x; cin >> x; pos.insert(x);
        auto itr3 = pos.lower_bound(x);
        itr3--; int y = *itr3;
        int z = *pos.lower_bound(x+1);
        auto itr = dif.find(z-y);
        if (itr != dif.end()) dif.erase(itr);
        dif.insert(z-x); dif.insert(x-y);
        auto itr2 = dif.end(); itr2--;
        cout << *itr2 << "\n";
    }
}
