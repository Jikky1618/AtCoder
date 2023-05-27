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

    bool inq = false, deq = false;
    int ans = 1;
    for(int i = 0; i < N - 1; i++){
        // 単調増加なら
        if(A[i] < A[i + 1]){
            // 今まで単調非増加だったなら -> リセット
            if(deq){
                deq = false;
                ans++;
            // でなければ、単調非減少
            }else{
                inq = true;
            }
        }
        // 単調減少なら
        if(A[i] > A[i + 1]){
            // 今まで単調減非減少だったなら -> リセット
            if(inq){
                inq = false;
                ans++;
            // でなければ、単調非増加
            }else{
                deq = true;
            }
        }
    }

    cout << ans << endl;
}