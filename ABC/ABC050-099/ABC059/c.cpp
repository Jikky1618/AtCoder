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
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    ll sum = 0, ans1 = 0, ans2 = 0;
    // 0, 2, 4,... 番目を正にする場合
    for(int i = 0; i < N; i++){
        sum += A[i];
        if(i % 2 == 0){
            if(sum <= 0) ans1 += abs(sum) + 1, sum = 1;
        }else{
            if(sum >= 0) ans1 += sum + 1, sum = -1;
        }
    }

    sum = 0;
    // 1, 3, 5,... 番目を正にする場合
    for(int i = 0; i < N; i++){
        sum += A[i];
        if(i % 2 == 1){
            if(sum <= 0) ans2 += abs(sum) + 1, sum = 1;
        }else{
            if(sum >= 0) ans2 += sum + 1, sum = -1;
        }
    }
    
    cout << min(ans1, ans2) << endl;
}