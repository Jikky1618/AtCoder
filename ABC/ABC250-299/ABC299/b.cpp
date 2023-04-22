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
    int N, T;
    cin >> N >> T;
    vector<int> C(N), R(N);
    for(int i = 0; i < N; i++) cin >> C[i];
    for(int i = 0; i < N; i++) cin >> R[i];

    int T1 = C.front();

    // Tの勝者
    int val = -1, win = -1;
    for(int i = 0; i < N; i++){
        if(C[i] == T && val < R[i]){
            win = i;
            val = R[i];
        }
    }

    if(win != -1){
        cout << win + 1 << endl;
        return 0;
    }

    // T1での勝者
    for(int i = 0; i < N; i++){
        if(C[i] == T1 && val < R[i]){
            win = i;
            val = R[i];
        }
    }

    cout << win + 1 << endl;
}