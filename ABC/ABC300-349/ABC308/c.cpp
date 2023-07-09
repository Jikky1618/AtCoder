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
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];

    //　{分子, 分母, id}
    vector<tuple<ll, ll, int>> P(N);
    for(int i = 0; i < N; i++){
        P[i] = {A[i], A[i] + B[i], i};
    }

    sort(P.begin(), P.end(), [](auto l, auto r){
        auto [ltop, lbottom, lid] = l;
        auto [rtop, rbottom, rid] = r;
        ll lval = ltop * rbottom;
        ll rval = rtop * lbottom;
        if(lval != rval){
            return lval > rval;
        }else{
            return lid < rid;
        }
    });

    debug(P);
    for(int i = 0; i < N; i++){
        auto [top, bottom, id] = P[i];
        cout << id + 1 << " \n"[i == N - 1];
    }
}