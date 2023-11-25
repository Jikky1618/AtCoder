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
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<int> cnt(N + 1);
    for(int i = 0; i < N; i++) if(A[i] <= N) cnt[A[i]]++;
    // 補集合を管理
    set<int> st;
    for(int i = 0; i <= N; i++) if(cnt[i] == 0) st.insert(i);

    while(Q--){
        int i, x; cin >> i >> x, i--;
        if(A[i] <= N){
            cnt[A[i]]--;
            if(cnt[A[i]] == 0) st.insert(A[i]);
        }
        A[i] = x;
        if(A[i] <= N){
            if(cnt[A[i]] == 0) st.erase(A[i]);
            cnt[A[i]]++;
        }
        cout << *st.begin() << '\n';
    }
}