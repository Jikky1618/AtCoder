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
    for(int i = 0; i < N; i++) cin >> P[i];

    multiset<int> st;
    for(int i = 0; i < K - 1; i++) st.insert(P[i]);

    for(int i = K - 1; i < N; i++){
        st.insert(P[i]);
        if((int)st.size() > K) st.erase(st.begin());
        cout << *st.begin() << '\n';
    }

}