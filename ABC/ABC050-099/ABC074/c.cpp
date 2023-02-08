#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double EPS = 1e-8;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    set<int> Water;
    for(int i = 0; i <= 30; i++){
        for(int j = 0; j <= 30; j++){
            int val = i * A * 100 + j * B * 100;
            if(F < val) continue;
            Water.insert(val);
        }
    }

    set<int> Sugar;
    for(int i = 0; i <= 1500; i++){
        for(int j = 0; j <= 1500; j++){
            int val = i * C + j * D;
            if(F < val) continue;
            Sugar.insert(val);
        }
    }

    double max = 0;
    int ans1 = 0, ans2 = 0;
    for(auto&& a: Water){
        for(auto&& b: Sugar){
            if(a + b == 0 || F < a + b) continue;
            if(a * E < 100 * b) continue;
            
            double val = (double)(100 * b) / (a + b);
            if(max < val + EPS){
                max = val;
                ans1 = a + b;
                ans2 = b;
            }
        }
    }

    cout << ans1 << " " << ans2 << endl;
}