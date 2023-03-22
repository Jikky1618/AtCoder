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
double to_deg(double rad){
    return rad * 180 / PI;
}
double to_rad(double deg){
    return deg / 180 * PI;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    double A, B;
    cin >> A >> B;

    if(A > B) swap(A, B);

    // θ = 0のとき
    if(2 * A / sqrt(3) <= B){
        cout << 2 * A / sqrt(3) << endl;
        return 0;
    }

    auto check = [&](double mid) -> bool {
        double val = A * cos(mid) - B * cos(30 - mid);
        return val > 0;
    };

    double low = to_rad(0), high = to_rad(30);
    for(int iter = 0; iter < 100; iter++){
        double mid = (low + high) / 2;
        if(check(mid)) low = mid;
        else high = mid;
    }

    double ans = B / cos(high);
    cout << ans << endl;
}