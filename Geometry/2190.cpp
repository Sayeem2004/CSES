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

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int T; std::cin >> T; while (T--) {
        vec<long long> A, B, C, D;
        A.read2(); B.read2(); C.read2(); D.read2();
        vec<long long> AB = B - A, AC = C - A, AD = D - A;
        vec<long long> CD = D - C, CA = A - C, CB = B - C;

        long long parallel = AB.cross2(CD), colinear = AB.cross2(AC);
        if (parallel == 0) {
            if (colinear != 0) { std::cout << "NO\n"; continue; }
            if (std::max(A.X, B.X) < std::min(C.X, D.X)) { std::cout << "NO\n"; continue; }
            if (std::max(A.Y, B.Y) < std::min(C.Y, D.Y)) { std::cout << "NO\n"; continue; }
            if (std::max(C.X, D.X) < std::min(A.X, B.X)) { std::cout << "NO\n"; continue; }
            if (std::max(C.Y, D.Y) < std::min(A.Y, B.Y)) { std::cout << "NO\n"; continue; }
            std::cout << "YES\n"; continue;
        }

        long long cross1 = AB.cross2(AC), cross2 = AB.cross2(AD);
        long long cross3 = CD.cross2(CA), cross4 = CD.cross2(CB);
        if ((cross1 < 0 && cross2 < 0) || (cross1 > 0 && cross2 > 0)) { std::cout << "NO\n"; continue; }
        if ((cross3 < 0 && cross4 < 0) || (cross3 > 0 && cross4 > 0)) { std::cout << "NO\n"; continue; }
        std::cout << "YES\n";
    }
}
