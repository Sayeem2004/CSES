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

    int N; std::cin >> N;
    std::vector<vec<long long>> P(N);
    for (vec<long long> &p : P) p.read2();

    long long area = 0, bound = 0;
    for (int i = 0; i < N; i++) {
        area += P[0].tri2(P[i], P[(i + 1) % N]);
        vec<long long> dif = P[(i + 1) % N] - P[i];
        bound += std::__gcd(std::abs(dif.X), std::abs(dif.Y));
    }

    std::cout << (std::abs(area) - bound + 2) / 2 << " ";
    std::cout << bound << "\n";
}
