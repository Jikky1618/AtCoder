#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    int N;
    cin >> N;

    // iを特定する
    int li = 0, ri = N;
    auto check1 = [&](int mid) -> bool {
        cout << "? " << 1 << " " << mid << " " << 1 << " " << N << endl;
        int in;
        cin >> in;
        return in == mid;
    };
    while(ri - li > 1){
        int mid = (li + ri) / 2;
        if(check1(mid)) li = mid;
        else ri = mid;
    }

    // jを特定する
    int lj = 0, rj = N;
    auto check2 = [&](int mid) -> bool {
        cout << "? " << 1 << " " << N << " " << 1 << " " << mid << endl;
        int in;
        cin >> in;
        return in == mid;
    };
    while(rj - lj > 1){
        int mid = (lj + rj) / 2;
        if(check2(mid)) lj = mid;
        else rj = mid;
    }

    cout << "! " << li + 1 << " " << lj + 1 << endl;
}