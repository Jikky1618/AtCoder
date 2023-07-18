#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

void solve(){
    int N;
    string S;
    cin >> N >> S;
    // 最初の文字
    char F = S.front();
    for(int i = 1; i < N; i++){
        // F より辞書順で大きい場所があれば Yes
        if(F < S[i]){
            cout << "Yes" << '\n';
            return;
        // F と同じ文字なら, そこで 2 分割
        }else if(F == S[i]){
            string X = S.substr(0, i);
            string Y = S.substr(i);
            if(X < Y){
                cout << "Yes" << '\n';
                return;
            }
        }
    }

    cout << "No" << '\n';
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int T;
    cin >> T;
    while(T--) solve();
}