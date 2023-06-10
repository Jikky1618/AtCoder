#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

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
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<ll> st, end;
    st.emplace_back(0); // 番兵
    for(int i = 0; i < N; i++){
        if(i % 2 == 1) st.emplace_back(A[i]);
        else end.emplace_back(A[i]);
    }
    st.emplace_back(INF), end.emplace_back(INF); // 一応の番兵
    debug(st, end);

    int M = (N + 1) / 2;
    // 累積和
    vector<ll> acc(M + 1);
    for(int i = 0; i < M; i++) acc[i + 1] = acc[i] + (end[i] - st[i]);
    debug(acc);

    int Q;
    cin >> Q;
    while(Q--){
        int l, r; cin >> l >> r;
        int ls = lower_bound(st.begin(), st.end(), l) - st.begin() - 1;
        int le = upper_bound(end.begin(), end.end(), l) - end.begin();
        int rs = lower_bound(st.begin(), st.end(), r) - st.begin() - 1;
        int re = upper_bound(end.begin(), end.end(), r) - end.begin();

        ll ans = 0;
        // l が区間内なら
        if(ls == le){
            ans += end[le] - l;
        }
        // r が区間内なら
        if(rs == re){
            ans += r - st[rs];
        }
        // 内包された区間を累積和から足す
        ans += acc[re] - acc[ls + 1];

        cout << ans << '\n';
    }
}