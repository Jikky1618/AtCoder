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
    int X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    vector<ll> A(X), B(Y), C(Z);
    for(int i = 0; i < X; i++) cin >> A[i];
    for(int i = 0; i < Y; i++) cin >> B[i];
    for(int i = 0; i < Z; i++) cin >> C[i];

    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());
    sort(C.begin(), C.end(), greater<ll>());

    using T = tuple<ll, int, int, int>;
    priority_queue<T> que;
    set<T> st;

    que.emplace(A[0] + B[0] + C[0], 0, 0, 0);

    while(K--){
        auto [val, x, y, z] = que.top(); que.pop();
        cout << val << "\n";

        // 次の値に遷移
        if(x + 1 < X){
            T nx1 = {A[x + 1] + B[y] + C[z], x + 1, y, z};
            if(!st.count(nx1)) st.insert(nx1), que.emplace(nx1); 
        }
        if(y + 1 < Y){
            T nx2 = {A[x] + B[y + 1] + C[z], x, y + 1, z};
            if(!st.count(nx2)) st.insert(nx2), que.emplace(nx2); 
        }
        if(z + 1 < Z){
            T nx3 = {A[x] + B[y] + C[z + 1], x, y, z + 1};
            if(!st.count(nx3)) st.insert(nx3), que.emplace(nx3);
        }
    }
}