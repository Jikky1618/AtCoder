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
    string S;
    cin >> N >> S;
    int Q;
    cin >> Q;

    vector<int> t(Q), x(Q);
    vector<char> c(Q);
    for(int i = 0; i < Q; i++) cin >> t[i] >> x[i] >> c[i], x[i]--;

    // 最後にクエリ 2, 3 が来た場所を調べる
    int last = -1;
    for(int i = Q - 1; i >= 0; i--){
        if(t[i] != 1){
            last = i;
            break;
        }
    }

    // クエリ 2, 3 が来る場合
    if(last != -1){
        for(int i = 0; i < last; i++){
            if(t[i] == 1){
                S[x[i]] = c[i];
            }
        }

        if(t[last] == 2){
            for(int i = 0; i < N; i++){
                S[i] = tolower(S[i]);
            }
        }
        if(t[last] == 3){
            for(int i = 0; i < N; i++){
                S[i] = toupper(S[i]);
            }
        }
        debug(t[last], last);
        for(int i = last + 1; i < Q; i++){
            if(t[i] == 1){
                S[x[i]] = c[i];
            }
        }
    // クエリ 2, 3 が来ない場合
    }else{
        for(int i = 0; i < Q; i++){
            if(t[i] == 1){
                S[x[i]] = c[i];
            }
        }
    }

    cout << S << endl;
}