#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

vector<string> graycode(int n) {
    if (n == 1) {
        vector<string> A = {"0", "1"};
        return A;
    }
    vector<string> T = graycode(n-1);
    vector<string> T2 = T;
    reverse(T2.begin(),T2.end());
    vector<string> A;
    for (auto x : T) {
        A.push_back("0"+x);
    }
    for (auto x : T2) {
        A.push_back("1"+x);
    }
    return A;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<string> V = graycode(n);
    for (auto x : V) {
        cout << x << "\n";
    }
}
