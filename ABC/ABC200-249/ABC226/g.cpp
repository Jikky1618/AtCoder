#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

bool solve(vector<ll> A, vector<ll> B){
    // 重さ x を体力 y の人に持たせる
    auto f = [&](int x, int y) -> void {
        ll cnt = min(A[x], B[y]);
        A[x] -= cnt, B[y] -= cnt, B[y - x] += cnt;
    };

    // 先に同じ重さ, 体力の人にできるだけ持たせる
    for(int i = 1; i <= 5; i++){
        f(i, i);
    }

    // 5から降順に荷物がどれだけ持てるか確認
    for(int i = 5; i >= 1; i--){
        for(int j = 5; j >= i; j--){
            f(i, j);
        }
    }
    
    bool flag = true;
    for(int i = 1; i <= 5; i++) if(A[i]) flag = false;
    return flag;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int T;
    cin >> T;
    while(T--){
        vector<ll> A(6), B(6); // 1-indexed
        for(int i = 1; i <= 5; i++) cin >> A[i];
        for(int i = 1; i <= 5; i++) cin >> B[i];
        cout << (solve(A, B) ? "Yes" : "No") << '\n';
    }
}