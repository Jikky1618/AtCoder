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
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D, A--, B--, C--, D--;
    string S;
    cin >> S;

    // 追い越し不要の場合
    if(C < D){
        bool flag = true;
        // 進めない場所があるかどうか
        for(int i = A; i < C - 1; i++){
            if(S[i] == '#' && S[i + 1] == '#') flag = false;
        }
        for(int i = B; i < D - 1; i++){
            if(S[i] == '#' && S[i + 1] == '#') flag = false;
        }
        cout << (flag ? "Yes" : "No") << endl;
    // 追い越しが必要な場合
    }else{
        bool flag = false;
        // 追い越し可能か判定
        for(int i = B; i <= D; i++){
            if(S[i - 1] == '.' && S[i] == '.' && S[i + 1] == '.') flag = true;
        }
        // 進めない場所があるかどうか
        for(int i = A; i < C - 1; i++){
            if(S[i] == '#' && S[i + 1] == '#') flag = false;
        }
        for(int i = B; i < D - 1; i++){
            if(S[i] == '#' && S[i + 1] == '#') flag = false;
        }
        cout << (flag ? "Yes" : "No") << endl;
    }
}