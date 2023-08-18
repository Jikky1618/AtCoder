#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    for(int i = 0; i < N; i++) cin >> P[i];

    set<int> st;
    int ans = N;
    for(int i = 0; i < K; i++) st.insert(P[i]), ans = min(ans, P[i]);

    cout << ans << endl; // i = K番目に大きい値

    for(int i = K; i < N; i++){
        if(P[i] > ans){ // P[i]がK番目より大きい場合
            st.erase(ans); // K + 1 番目はpop
            st.insert(P[i]); // P[i] を挿入
            ans = *st.lower_bound(ans); // ansより大きい最小の要素を二分探索
        }

        cout << ans << endl;
    }
}