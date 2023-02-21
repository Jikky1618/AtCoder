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
    int N, L, K;
    cin >> N >> L >> K;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];


    auto check = [&](int mid) -> bool {
        int cnt = 0, pos = 0;
        for(int i = 0; i < N; i++){
            // L - A[i] >= mid の条件も忘れずに！
            if(mid <= A[i] - pos && L - A[i] >= mid) cnt++, pos = A[i];
        }
        return K <= cnt;
    };

    int ok = -1, ng = L + 1;
    while(ng - ok > 1){
        int mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
}