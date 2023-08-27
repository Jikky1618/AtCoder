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
    int M;
    cin >> M;
    vector<int> D(M);
    for(int i = 0; i < M; i++) cin >> D[i];

    int sum = 0;
    for(int i = 0; i < M; i++) sum += D[i];

    // 真ん中の日の月と日を求める
    int mid = sum / 2;
    for(int i = 0; i < M; i++){
        if(mid < D[i]){
            cout << i + 1 << " " << mid + 1 << endl;
            return 0;
        }else{
            mid -= D[i];
        }
    }
}