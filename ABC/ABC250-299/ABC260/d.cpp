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
    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    for(int i = 0; i < N; i++) cin >> P[i], P[i]--;

    set<int> st; // 一番上にあるカードの集合
    vector<vector<int>> C(N); // 先頭がiの山にあるカードの集合
    vector<int> ans(N, -1);
    for(int i = 0; i < N; i++){
        // P[i]以上で最小の一番上にあるカードを探す
        auto itr = st.lower_bound(P[i]);
        // なければ、山を作る
        if(itr == st.end()){
            st.insert(P[i]);
            C[P[i]].emplace_back(P[i]);
        // あれば、valの山に載せる
        }else{
            int val = *itr;
            st.insert(P[i]), st.erase(itr);
            swap(C[P[i]], C[val]);
            C[P[i]].emplace_back(P[i]);
        }

        // サイズがK以上なら消去する
        if((int)C[P[i]].size() >= K){
            for(auto j: C[P[i]]) ans[j] = i + 1;
            C[P[i]].clear();
            st.erase(P[i]);
        }
    }

    for(int i = 0; i < N; i++){
        cout << ans[i] << '\n';
    }
}