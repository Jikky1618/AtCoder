#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

template<class T, class U>
T ceil(T x, U y){
    return (x ? (x + y - 1) / y : x / y);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, H;
    cin >> N >> H;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];

    int A_max = *max_element(A.begin(), A.end());
    
    vector<int> V;
    for(int i = 0; i < N; i++) if(A_max < B[i]) V.emplace_back(B[i]);
    sort(V.begin(), V.end(), greater<int>());

    int ans = 0;
    for(auto e: V){
        H -= e, ans++;
        if(H <= 0){
            cout << ans << endl;
            return 0;
        }
    }

    ans += ceil(H, A_max);
    cout << ans << endl;
}