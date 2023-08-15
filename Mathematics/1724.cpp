#include <bits/stdc++.h>

template<typename T> struct matrix { // Variables & Constructors
    T R, C, D, MOD; std::vector<std::vector<T>> M; matrix(T N) : matrix(N, N) { }
    matrix(T R, T C, T D = 0, T MOD = 1e9+7) : R(R), C(C), D(D), MOD(MOD), M(R, std::vector<T>(C, D)) { }
    matrix(std::vector<std::vector<T>> M, T MOD = 1e9+7) : R(M.size()), C(M[0].size()), MOD(MOD), M(M) { }

    matrix operator +(const matrix &O) const { matrix A(R, C); for (T i = 0; i < R; i++) // Operators
        for (T q = 0; q < C; q++) A.M[i][q] = (M[i][q] + O.M[i][q]); return A; }
    matrix operator -(const matrix &O) const { matrix A(R, C); for (T i = 0; i < R; i++)
        for (T q = 0; q < C; q++) A.M[i][q] = (M[i][q] - O.M[i][q]); return A; }
    matrix operator *(const matrix &O) const { matrix A(R, O.C, D); for (T i = 0; i < R; i++) for (T q = 0; q < O.C; q++)
        for (T r = 0; r < C; r++) A.M[i][r] = std::min(A.M[i][r], M[i][q] + O.M[q][r]); return A; }
    matrix operator ^(const T &P) const { if (P == 1) { return *this; }
        matrix A = *this ^ (P >> 1); A *= A; if (P & 1) A *= *this; return A; }
    std::vector<T> operator &(const std::vector<T> &V) const { std::vector<T> A(R); for (T i = 0; i < R; i++)
        for (T q = 0; q < C; q++) A[i] = (A[i] + M[i][q] * V[q]); return A; }

    matrix operator +=(const matrix &O) { return *this = *this + O; } // Assignments
    matrix operator -=(const matrix &O) { return *this = *this - O; }
    matrix operator *=(const matrix &O) { return *this = *this * O; }
    matrix operator ^=(const T &P) { return *this = *this ^ P; }
    void print() { for (T i = 0; i < R; i++) for (T q = 0; q < C; q++) std::cout << M[i][q] << " \n"[q == C-1]; }
};

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    long long N, M, K; std::cin >> N >> M >> K;
    long long INF = 2e18;
    matrix<long long> ADJ(N, N, INF);

    for (int i = 0; i < M; i++) {
        long long u, v, w; std::cin >> u >> v >> w;
        ADJ.M[u-1][v-1] = std::min(ADJ.M[u-1][v-1], w);
    }

    ADJ ^= K; if (ADJ.M[0][N-1] == INF) ADJ.M[0][N-1] = -1;
    std::cout << ADJ.M[0][N-1] << "\n";
}
