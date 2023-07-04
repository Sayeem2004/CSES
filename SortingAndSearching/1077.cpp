#include <bits/stdc++.h>

long long diff(long long m, long long sl, long long su,
    std::multiset<long long> &L, std::multiset<long long> &U) {

    return (su - m * U.size()) + (m * L.size() - sl);
}

void move_up(long long &sl, long long &su,
    std::multiset<long long> &L, std::multiset<long long> &U) {

    long long val = *L.rbegin();
    L.erase(L.find(val)); sl -= val;
    U.insert(val); su += val;
}

void move_down(long long &sl, long long &su,
    std::multiset<long long> &L, std::multiset<long long> &U) {

    long long val = *U.begin();
    U.erase(U.find(val)); su -= val;
    L.insert(val); sl += val;
}

void insert(long long val, long long &sl, long long &su,
    std::multiset<long long> &L, std::multiset<long long> &U) {

    if (L.empty()) { L.insert(val); sl += val; return; }
    long long med = *L.rbegin();

    if (val > med) {
        U.insert(val); su += val;
        if (U.size() > L.size()) move_down(sl, su, L, U);
    } else {
        L.insert(val); sl += val;
        if (L.size() > U.size() + 1) move_up(sl, su, L, U);
    }
}

void remove(long long val, long long &sl, long long &su,
    std::multiset<long long> &L, std::multiset<long long> &U) {

    if (L.empty()) return;
    long long med = *L.rbegin();

    if (val > med) {
        U.erase(U.find(val)); su -= val;
        if (U.size() < L.size()-1) move_up(sl, su, L, U);
    } else {
        L.erase(L.find(val)); sl -= val;
        if (L.size() < U.size()) move_down(sl, su, L, U);
    }
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long N, K; std::cin >> N >> K;
    std::vector<long long> V(N);
    for (long long &v : V) std::cin >> v;

    std::multiset<long long> L, U;
    long long sl = 0, su = 0;
    for (int i = 0; i < K; i++) insert(V[i], sl, su, L, U);
    std::cout << diff(*L.rbegin(), sl, su, L, U) << " ";

    for (int i = K; i < N; i++) {
        remove(V[i-K], sl, su, L, U);
        insert(V[i], sl, su, L, U);
        std::cout << diff(*L.rbegin(), sl, su, L, U) << " ";
    }

    std::cout << "\n";
}
