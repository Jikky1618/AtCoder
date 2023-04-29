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

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int A, B, C;
    cin >> A >> B >> C;

    auto f = [&](double t) -> double {
        return A * t + B * sin(C * t * PI);
    };

    double left = 1, right = 100;
    for(int iter = 0; iter < 100; iter++){
        double mid = (left + right) / 2;
        if(f(mid) < 100) left = mid;
        else right = mid;
    }

    cout << right << endl;
}