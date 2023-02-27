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
    // 入力
    int N, M;
    cin >> N >> M;
    vector<string> S(N), T(M);
    for(int i = 0; i < N; i++) cin >> S[i];
    for(int i = 0; i < M; i++) cin >> T[i];

    // next_permutationできるようにソート
    sort(S.begin(), S.end());

    // 二分探索できるようにsetにTを挿入
    set<string> st;
    for(int i = 0; i < M; i++) st.insert(T[i]);

    // dfs
    // pos := Sのpos番目、res := _が使える文字数、X := 現在のX
    auto dfs = [&](auto &&self, int pos, int rem, string X) -> string {
        if(pos == N){
            if(st.count(X)) return "";
            if(X.size() < 3 || X.size() > 16) return "";
            return X;
        }

        // _の数を全探索
        for(int i = 0; i <= rem; i++){
            if(pos != N - 1 && i == 0) continue; // 最後以外なら1個以上_を挿入する 
            if(pos == N - 1 && i != 0) continue; // 最後なら_を挿入しない

             // 次の文字列を構築する
            string next = X + S[pos];
            for(int j = 0; j < i; j++) next += '_';

            string res = self(self, pos + 1, rem - i, next);
            if(res != "") return res;
        }

        return "";
    };

    int remain = 16; //追加できる_の数
    for(int i = 0; i < N; i++) remain -= S[i].size();

    do{
        string ans = dfs(dfs, 0, remain, "");
        if(ans != ""){
            cout << ans << endl;
            return 0;
        }
    }while(next_permutation(S.begin(), S.end()));

    cout << -1 << endl;
}