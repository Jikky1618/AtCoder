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
    if(M < 2 * N || 4 * N < M){
        cout << -1 << " " << -1 << " " << -1 << endl;
    }else if(M < 3 * N){
        cout << 3 * N - M << " " << M - 2 * N << " " << 0 << endl;
    }else{
        cout << 0 << " " << 4 * N - M << " " << M - 3 * N << endl;
    }
}