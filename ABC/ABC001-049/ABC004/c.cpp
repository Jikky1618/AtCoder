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
    vector<int> A = {1, 2, 3, 4, 5, 6};
    int N;
    cin >> N;
    
    int cycle_cnt = 0;
    auto V = A;
    while(1){
        swap(V[cycle_cnt % 5], V[cycle_cnt % 5 + 1]);
        cycle_cnt++;
        if(V == A) break;
    }

    N %= cycle_cnt;
    for(int i = 0; i < N; i++){
        swap(A[i % 5], A[i % 5 + 1]);
    }
    for(int i = 0; i < 6; i++) cout << A[i];
    cout << endl;
}