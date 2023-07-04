#include <bits/stdc++.h>

void swap(int &curr, int v1, int v2, int va, int vb, std::map<int, int> &M) {
    int p1 = M[v1], p2 = M[v2];
    int np1, np2;

    if (v1 == va) np1 = M[vb];
    else if (v1 == vb) np1 = M[va];
    else np1 = p1;

    if (v2 == va) np2 = M[vb];
    else if (v2 == vb) np2 = M[va];
    else np2 = p2;

    if (p1 < p2 && np1 > np2) curr++;
    if (p1 > p2 && np1 < np2) curr--;
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, Q; std::cin >> N >> Q;

    std::vector<int> V(N);
    std::map<int, int> M;
    for (int i = 0; i < N; ++i) {
        std::cin >> V[i]; M[V[i]] = i;
    }

    int curr = 1;
    for (int i = 1; i < N; i++) {
        if (M[i] > M[i+1]) curr++;
    }

    for (int i = 0; i < Q; i++) {
        int a, b; std::cin >> a >> b; a--; b--;
        int va = V[a], vb = V[b];

        if (va != 1) swap(curr, va-1, va, va, vb, M);
        if (va != N) swap(curr, va, va+1, va, vb, M);
        if (vb != 1 && va != vb-1) swap(curr, vb-1, vb, va, vb, M);
        if (vb != N && va != vb+1) swap(curr, vb, vb+1, va, vb, M);

        M[va] = b; M[vb] = a;
        std::swap(V[a], V[b]);
        std::cout << curr << "\n";
    }
}
