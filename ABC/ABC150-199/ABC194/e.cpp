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
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    map<int, int> cnt;
    for(int i = 0; i < M; i++) cnt[A[i]]++;

    set<int> st; // M個の連続部分列にない数
    for(int i = 0; i <= M; i++){
        if(!cnt.count(i)){
            st.insert(i);
        }
    }

    int ans = *st.begin();
    for(int i = 0; i < N - M; i++){
        cnt[A[i]]--;
        if(cnt[A[i]] == 0) cnt.erase(A[i]), st.insert(A[i]);

        cnt[A[i + M]]++;
        if(st.count(A[i + M])) st.erase(A[i + M]);

        ans = min(ans, *st.begin());
    }

    cout << ans << endl;
}