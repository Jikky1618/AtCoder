#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <atcoder/modint>
using namespace atcoder;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

template <class T>
struct Matrix {
    int m, n;
    vector<vector<T>> A;
    
    Matrix(int H, int W): m(H), n(W), A(H, vector<T>(W)) {}
    Matrix(const vector<vector<T>>& V): m(V.size()), n(V[0].size()), A(V) {}
    Matrix() = default;
    bool operator == (const Matrix& other) const {
        return *this->A == other.A;
    }
    bool operator != (const Matrix& other) const {
        return *this->A != other.A;
    }
    vector<T> operator [] (int i) const {
        return A[i];
    }
    vector<T>& operator [] (int i) {
        return A[i];
    }
    Matrix operator + (const Matrix& other) const {
        return *this += other;
    }
    Matrix operator - (const Matrix& other) const {
        return *this -= other;
    }
    Matrix operator * (const T& other) const {
        return *this *= other;
    }
    Matrix operator * (const Matrix& other) const {
        return *this *= other;
    }
    Matrix operator += (const Matrix& other) {
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                A[i][j] += other[i][j];
            }
        }
        return *this;
    }
    Matrix operator -= (const Matrix& other) {
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                A[i][j] -= other[i][j];
            }
        }
        return *this;
    }
    Matrix operator *= (const T& other) {
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                A[i][j] *= other;
            }
        }
        return *this;
    }
    Matrix operator *= (const Matrix& other) {
        assert(n == other.m);
        Matrix res(m, other.n);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < other.n; j++){
                for(int k = 0; k < n; k++){
                    res[i][j] += A[i][k] * other[k][j];
                }
            }
        }
        return (*this) = res;
    }
    Matrix pow(ll d) const {
        assert(m == n);
        Matrix res(m, n), x(*this);
        for(int i = 0; i < m; i++) res[i][i] = 1;
        while(d > 0){
            if(d & 1) res *= x;
            x *= x;
            d >>= 1;
        }
        return res;
    }
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll A, M, X;
    cin >> A >> X >> M;

    modint::set_mod(M);
    Matrix<modint> mat({{A, 1}, {0, 1}});
    mat = mat.pow(X);
    debug(mat.A);
    cout << mat[0][1].val() << '\n';
}