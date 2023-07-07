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

    auto input = [&]() -> int {
        string s;
        cin >> s;
        if(s == "Male") return 0;
        if(s == "Female") return 1;
        if(s == "Vacant") return 2;
        return -1;
    };

    auto output = [&](int pos) -> void {
        cout << pos << endl;
    };

    // 席0には誰が座っているか
    output(0);
    int first = input();
    debug(first);
    if(first == 2){
        return 0;
    }

    // 0: mid 番目以前に空席
    // 1: mid 番目以降に空席
    // 2: mid 番目が空席
    auto check = [&](int mid) -> int {
        output(mid);
        int val = input();
        
        if(val == 2) return 2;
        // mid % 2 と first % 2 の偶奇が一致 -> 空席までは同じ値
        // mid % 2 と first % 2 の偶奇が異なる -> 空席までは違う値
        if((mid % 2 == 0) && (val == first)) return 1;
        if((mid % 2 == 1) && (val != first)) return 1;
        return 0;
    };

    // 偶奇が入れ替わる場所を二分探索
    int ok = 0, ng = N;
    while(ng - ok > 1){
        int mid = (ok + ng) / 2;
        int res = check(mid);
        debug(res);
        if(res == 0){
            ng = mid;
        }else if(res == 1){
            ok = mid;
        }else{
            return 0;
        }
    }
}