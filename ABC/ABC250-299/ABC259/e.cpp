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
    vector<int> m(N);
    vector<vector<int>> p(N), e(N);
    for(int i = 0; i < N; i++){
        cin >> m[i];
        p[i].assign(m[i], 0), e[i].assign(m[i], 0);
        for(int j = 0; j < m[i]; j++){
            cin >> p[i][j] >> e[i][j];
        }
    }

    // M[p] := 素因数 p の最大の個数
    map<int, int> M;
    // id[p] := 素因数 p の最大の個数をもつ唯一の id
    map<int, int> id;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < m[i]; j++){
        	// e[i][j] が最大値のとき
            if(M[p[i][j]] < e[i][j]){
                M[p[i][j]] = e[i][j];
            	// id[p[i][j]] を更新
                id[p[i][j]] = i;
                // 最大値が他の整数にも存在する場合
            }else if(M[p[i][j]] == e[i][j]){
                // id[p[i][j]] を削除
                id.erase(p[i][j]);
            }
        }
    }

    set<int> st;
    for(auto [key, val]: id){
        st.insert(val);
    }
    
    // 最大の個数をもつ A[i] が欠けると LCM も変化する
    // 最大の個数をもつ A[i] が全て存在する場合も含めて答えは st.size() + 1
    // 全て最大の個数をもつ場合は N
    int ans = (int(st.size()) == N ? N : int(st.size()) + 1);
    cout << ans << endl;
}