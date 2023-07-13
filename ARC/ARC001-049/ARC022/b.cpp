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
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    int ans = 0;
    // しゃくとり法で他の値が含まれない最大の区間を求める
    set<int> st;
    for(int left = 0, right = 0; left < N; left++){
        right = max(left, right);
        // 値が重複しない区間 [left, right) を求める
        while(right < N && !st.count(A[right])) st.insert(A[right]), right++;
        debug(st, left, right);
        ans = max(ans, right - left);
        st.erase(A[left]); // A[left] を左端外に
    }

    cout << ans << endl;
}