#include <bits/stdc++.h>

template <typename T> struct vec { // Variables & Constructors
    T X, Y, Z; vec() : X(0), Y(0), Z(0) { } vec(T x) : X(x), Y(0), Z(0) { }
    vec(T x, T y) : X(x), Y(y), Z(0) { } vec(T x, T y, T z) : X(x), Y(y), Z(z) { }
    void read2() { std::cin >> X >> Y; } void read3() { std::cin >> X >> Y >> Z; }

    vec operator *(const T &c) { return vec(X * c, Y * c, Z * c); } // Mutators
    vec operator /(const T &c) { return vec(X / c, Y / c, Z / c); }
    vec operator +(const vec &p) { return vec(X + p.X, Y + p.Y, Z + p.Z); }
    vec operator -(const vec &p) { return vec(X - p.X, Y - p.Y, Z - p.Z); }
    bool operator <(const vec &p) const noexcept { return std::tie(X, Y, Z) < std::tie(p.X, p.Y, p.Z); }

    T norm() { return X*X + Y*Y + Z*Z; } // ||X + Y|| < ||X|| + ||Y||, |X * Y| < ||X|| * ||Y||
    T dot(vec &p) { return X*p.X + Y*p.Y + Z*p.Z; } // cos(theta), X x Y = 0 if X || Y
    T cross2(const vec &p) { return X*p.Y - Y*p.X; } // RHR, > 0 if p CCW of this, < 0 if p CW of this
    T tri2(vec &p, vec &q) { return (p - *this).cross2(q - *this); } // 2 * area of triangle
    vec cross3(vec &p) { return vec(Y*p.Z - Z*p.Y, Z*p.X - X*p.Z, X*p.Y - Y*p.X); } // sin(theta), X x Y = -Y x X
};

bool intersect(vec<long long> &A, vec<long long> &B, vec<long long> &C, vec<long long> &D) {
    vec<long long> AB = B - A, AC = C - A, AD = D - A;
    vec<long long> CD = D - C, CA = A - C, CB = B - C;

    long long parallel = AB.cross2(CD), colinear = AB.cross2(AC);
    if (parallel == 0) {
        if (colinear != 0) return false;
        if (std::max(A.X, B.X) < std::min(C.X, D.X)) return false;
        if (std::max(A.Y, B.Y) < std::min(C.Y, D.Y)) return false;
        if (std::max(C.X, D.X) < std::min(A.X, B.X)) return false;
        if (std::max(C.Y, D.Y) < std::min(A.Y, B.Y)) return false;
        return true;
    }

    long long cross1 = AB.cross2(AC), cross2 = AB.cross2(AD);
    long long cross3 = CD.cross2(CA), cross4 = CD.cross2(CB);
    if ((cross1 < 0 && cross2 < 0) || (cross1 > 0 && cross2 > 0)) return false;
    if ((cross3 < 0 && cross4 < 0) || (cross3 > 0 && cross4 > 0)) return false;
    return true;
}

bool online(vec<long long> &A, vec<long long> &B, vec<long long> &C) {
    vec<long long> AB = B - A, AC = C - A;
    long long colinear = AB.cross2(AC);

    if (colinear != 0) return false;
    if (std::min(A.X, B.X) > C.X || std::max(A.X, B.X) < C.X) return false;
    if (std::min(A.Y, B.Y) > C.Y || std::max(A.Y, B.Y) < C.Y) return false;
    return true;
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int N, M; std::cin >> N >> M;
    std::vector<vec<long long>> P(N);
    for (int i = 0; i < N; i++) P[i].read2();

    for (int i = 0; i < M; i++) {
        vec<long long> V; V.read2();
        vec<long long> O(V.X + 1, 1234567890);

        int cnt = 0, on = 0;
        for (int q = 0; q < N; q++) {
            int r = (q + 1) % N;
            if (online(P[q], P[r], V)) { on++; break; }
            if (intersect(V, O, P[q], P[r])) cnt++;
        }

        if (on) std::cout << "BOUNDARY\n";
        else if (cnt % 2) std::cout << "INSIDE\n";
        else std::cout << "OUTSIDE\n";
    }
}
