#include <bits/stdc++.h>
using namespace std;
using ll = long long;


struct Point{
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};
inline Point operator - (const Point &p, const Point &q){return Point(p.x - q.x, p.y - q.y);}
inline int cross(const Point &p, const Point &q){return p.x * q.y - p.y * q.x;}

int ccw(const Point &a, const Point &b, const Point &c){
    if (cross(b-a, c-a) > 0) return 1; // ccw
    if (cross(b-a, c-a) < 0) return -1; // cw
    return 0; // collinear
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    vector<Point> P(4);
    for(int i = 0; i < 4; i++) cin >> P[i].x >> P[i].y;

    bool ans = true;
    for(int i = 0; i < 4; i++){
        Point A = P[i];
        Point B = P[(i + 1) % 4];
        Point C = P[(i + 2) % 4];
        if(ccw(A, B, C) != 1){
            ans = false;
        }
    }

    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}