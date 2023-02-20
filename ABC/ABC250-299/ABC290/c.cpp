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
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    set<int> st;
    for(int i = 0; i < N; i++) st.insert(A[i]);

    for(int i = 0; i <= K; i++){
        if(st.count(i) == 0){
            cout << i << endl;
            return 0;
        }
    }
    cout << K << endl;
}