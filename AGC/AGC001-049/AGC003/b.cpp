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
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // 0で区切ったグループを作成
    vector<ll> groups;
    groups.emplace_back(0);
    for(int i = 0; i < N; i++){
        if(A[i] == 0){
            if(groups.back() != 0) groups.emplace_back(0);
        }else{
            groups.back() += A[i];
        }
    }

    debug(groups);
    ll ans = 0;
    for(auto g: groups){
        ans += g / 2;
    }

    cout << ans << endl;
}