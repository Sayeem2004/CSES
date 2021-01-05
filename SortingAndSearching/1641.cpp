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
    int n, k; cin >> n >> k;
    vector<int> v(n), v2(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v[i] = x; v2[i] = x;
    }
    sort(all(v2));
    int a, b, c;
    bool imp = true;
    for (int i = 0; i < n; i++) {
        int curr = k-v2[i];
        int j = i+1, q = n-1;
        while (j < q) {
            if (v2[j]+v2[q] < curr) j++;
            if (v2[j]+v2[q] > curr) q--;
            if (v2[j]+v2[q] == curr) break;
        }
        if (v2[j]+v2[q]+v2[i] == k && q != j) {
            a = v2[i]; b = v2[j]; c = v2[q];
            imp = false; break;
        }
    }
    if (imp) {
        cout << "IMPOSSIBLE" << "\n";
    } else {
        bool a2 = true, b2 = true, c2 = true;
        for (int i = 0; i < n; i++) {
            if (v[i] == a && a2) {
                cout << i+1 << "\n";
                a2 = false; continue;
            }
            if (v[i] == b && b2) {
                cout << i+1 << "\n";
                b2 = false; continue;
            }
            if (v[i] == c && c2) {
                cout << i+1 << "\n";
                c2 = false; continue;
            }
        }
    }
}
