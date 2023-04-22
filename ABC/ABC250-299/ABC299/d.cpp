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

    auto check = [&](int mid) -> bool {
        cout << "? " << mid + 1 << endl;
        int val;
        cin >> val;

        return val == 0;
    };

    // 値が必ず0となっている値を二分探索
    int ok = -1, ng = N;
    for(int i = 0; i < 20; i++){
        int mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }

    cout << "! " << ok + 1 << endl;
}