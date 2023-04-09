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
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    set<ll> st;
    st.insert(0);
    for(int i = 0; i < K; i++){
        auto it = st.begin(); // 貪欲的に最小値
        ll val = *it;
        st.erase(it);

        // 次の値に遷移
        for(int j = 0; j < N; j++){
            st.insert(val + A[j]);
        }
    }

    // K番目の値は先頭になっている
    cout << *st.begin() << endl;
}