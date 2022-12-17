#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int Q;
    cin >> Q;

    int N = 1 << 20;
    vector<ll> A(N, -1);
    set<int> st; // 値が確定していない要素
    for(int i = 0; i < N; i++) st.insert(i); // 最初は全て確定していない

    while(Q--){
        ll t, x; cin >> t >> x;
        if(t == 1){
            auto itr = st.lower_bound(x % N); // x%N以降の未確定要素を二分探索
            if(itr == st.end()) itr = st.begin(); // なければ最初の未確定要素
            A[*itr] = x;
            st.erase(itr);
        }
        if(t == 2){
            cout << A[x % N] << endl;
        }
    }
    return 0;
}