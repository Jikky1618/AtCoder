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

    int cnt = 0;
    stack<pair<int, int>> stk;
    for(int i = 0; i < N; i++){
        cnt++;
        // A[i]が一番上にないとき
        if(stk.empty() || stk.top().first != A[i]){
            stk.push({A[i], 1});
        // A[i]が一番上にあるとき
        }else{
            stk.top().second++;
        }

        if(stk.top().first == stk.top().second){
            cnt -= stk.top().second;
            stk.pop();
        }

        cout << cnt << '\n';
    }
}