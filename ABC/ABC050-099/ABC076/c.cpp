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
    string S, T;
    cin >> S >> T;

    vector<string> V;
    int N = S.size(), M = T.size();
    for(int i = 0; i < N - M + 1; i++){
        // 判定
        bool flag = true;
        for(int j = 0; j < M; j++){
            if(S[i + j] != T[j] && S[i + j] != '?'){
                flag = false;
            };
        }
        if(!flag) continue;

        // S1の作成
        string S1 = S.substr(0, i);
        for(int j = 0; j < M; j++) S1 += T[j];
        S1 += S.substr(i + M);
        // S1を配列に突っ込む
        V.push_back(S1);
    }

    if(V.size() == 0){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    
    for(auto&& v: V){
        for(auto&& c: v){
            if(c == '?') c = 'a';
        }
    }
    sort(V.begin(), V.end());
    cout << V.front() << endl;
}