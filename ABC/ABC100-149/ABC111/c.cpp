#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> V(N);
    for(int i = 0; i < N; i++) cin >> V[i];

    // Case1: 1種類のみ
    set<int> st;
    for(int i = 0; i < N; i++){
        st.insert(V[i]);
    }
    if(st.size() == 1){
        cout << V.size() / 2 << endl;
        return 0;
    }

    // Case2: 2種類以上
    vector<int> f(1e5+1), s(1e5+1);
    for(int i = 0; i < N; i++){
        // (i % 2 == 0 ? f[V[i]] : s[V[i]])++;
        if(i % 2 == 0){
            f[V[i]]++;
        }else{
            s[V[i]]++;
        }
    }

    auto mode = [&](vector<int>& A) -> pair<int, int> {
        int m1 = 0, m2 = 0; // m1: 配列Aの最頻値, m2: 配列Aの2番目の頻出値
        int val1 = -1, val2 = -1; // 最頻値の値
        for(int i = 0; i < A.size(); i++){
            if(val2 < A[i]){
                m2 = i, val2 = A[i];
            }
            if(val1 < val2){
                swap(m1, m2), swap(val1, val2);
            }
        }
        return {m1, m2};
    };

    auto F = mode(f), S = mode(s);
    int ans = INF;
    // f1, s1
    if(F.first != S.first) ans = min(ans, N - f[F.first] - s[S.first]);
    // f1, s2
    if(F.first != S.second) ans = min(ans, N - f[F.first] - s[S.second]);
    // f2, s1
    if(F.second != S.first) ans = min(ans, N - f[F.second] - s[S.first]);

    cout << ans << endl;
}