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
    int N, K, R, S, P;
    cin >> N >> K >> R >> S >> P;
    string T;
    cin >> T;

    vector<int> point(N), A(N); // point[i] := i回目で勝利したときの特典, A[i] := i回目で勝利したかどうか
    for(int i = 0; i < N; i++){
        if(T[i] == 'r') point[i] = P;
        if(T[i] == 's') point[i] = R;
        if(T[i] == 'p') point[i] = S;
    }

    for(int i = 0; i < N; i++){
        // K回目まではすべて勝つ
        if(i < K){
            A[i] = 1;
            continue;
        }

        // i回目とi - K回目が同じ手なら
        if(T[i] == T[i - K]){
            // i - K回目で勝っていないなら、i回目は勝つ
            if(A[i - K] == 0){
                A[i] = 1;
                continue;
            }
            // i - K回目よりi回目の方が得点が高いならi回目で勝ち、i - K回目で別の手を出す
            if(point[i] > point[i - K]){
                A[i] = 1, A[i - K] = 0;
            }
        // i回目とi - K回目が違う手ならi回目は勝つ
        }else{
            A[i] = 1;
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++) if(A[i] == 1) ans += point[i];

    cout << ans << endl;
}