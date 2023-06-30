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
    vector<ll> A(N), B(N);
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i];
    }

    // A[i] + B[i] となる配列 C を用意
    vector<pair<ll, int>> C(N);
    for(int i = 0; i < N; i++) C[i] = {A[i] + B[i], i};
    sort(C.begin(), C.end(), greater<pair<ll, int>>());

    ll Takahashi = 0, Aoki = 0;
    for(int i = 0; i < N; i++){
        if(i % 2 == 0){
            Takahashi += A[C[i].second];
        }else{
            Aoki += B[C[i].second];
        }
    }

    cout << Takahashi - Aoki << endl;
}