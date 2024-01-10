#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const double INF = 1LL << 60;
const double EPS = 1e-10;
const double PI = acos(-1);

struct Point {
    double x, y;
    Point(double x = 0.0, double y = 0.0): x(x), y(y) {}

    Point operator - () const {
        return Point(*this) *= -1;
    }
    Point operator + (const Point& p) const {
        return Point(*this) += p;
    }
    Point operator - (const Point& p) const {
        return Point(*this) -= p;
    }
    Point operator * (const double& c) const {
        return Point(*this) *= c;
    }
    Point operator / (const double& c) const {
        return Point(*this) /= c;
    }
    Point& operator += (const Point& p){
        x += p.x; y += p.y;
        return (*this);
    }
    Point& operator -= (const Point& p){
        x -= p.x; y -= p.y;
        return (*this);
    }
    Point& operator *= (const double& c){
        x *= c; y *= c;
        return (*this);
    }
    Point& operator /= (const double& c){
        x /= c; y /= c;
        return (*this);
    }
    friend Point operator * (const double& c, const Point& p){
        return p * c;
    }
    double dot(const Point& other) const {
        return x * other.x + y * other.y;
    }
    double cross(const Point& other) const {
        return x * other.y - y * other.x;
    }
    double angle() const {
        return atan2(y, x);
    }
};

bool colinear(Point a, Point b, Point c){
    return (b.x - a.x) * (c.y - a.y) == (b.y - a.y) * (c.x - a.x);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, K;
    cin >> N >> K;
    vector<Point> p(N);
    for(int i = 0; i < N; i++) cin >> p[i].x >> p[i].y;

    // corner case: K = 1
    if(K == 1){
        cout << "Infinity" << endl;
        return 0;
    }

    // 点を 2 つ全探索して, 直線の方程式を求める
    set<vector<int>> st;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            vector<int> cnt{i, j};
            for(int k = 0; k < N; k++){
                if(i == k || j == k) continue;
                if(colinear(p[i], p[j], p[k])) cnt.emplace_back(k);
            }
            sort(cnt.begin(), cnt.end());
            if(int(cnt.size()) >= K) st.insert(cnt);
        }
    }

    int ans = st.size();
    debug(st);
    cout << ans << endl;
}