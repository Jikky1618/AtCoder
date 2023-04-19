#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const double PI = acos(-1);

struct Point {
    double x, y;
    Point(double x = 0.0, double y = 0.0): x(x), y(y) {}
};
inline Point operator + (const Point& p, const Point& q){
    return Point(p.x + q.x, p.y + q.y);
}
inline Point operator - (const Point& p, const Point& q){
    return Point(p.x - q.x, p.y - q.y);
}
inline Point operator / (const Point& p, double a){
    return Point(p.x / a, p.y / a);
}
inline Point rot(const Point& p, double ang){
    return Point(cos(ang) * p.x - sin(ang) * p.y, sin(ang) * p.x + cos(ang) * p.y);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    Point P, Q;
    cin >> P.x >> P.y >> Q.x >> Q.y;

    // P, Qの中点
    Point M = (P + Q) / 2;
    // Pを並行移動させる
    Point D1 = P - M;
    // Pを回転移動させる
    Point D2 = rot(D1, 2 * PI / N);
    // 回転させた点にMを足す
    Point ans = D2 + M;

    cout << ans.x << " " << ans.y << endl;
}