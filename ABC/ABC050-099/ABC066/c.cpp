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
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    deque<int> B;
    bool rev = false;
    for(int i = 0; i < N; i++){
        if(!rev) B.push_back(A[i]);
        else B.push_front(A[i]);
        rev = !rev;
    }
    if(rev) reverse(B.begin(), B.end());
    for(int i = 0; i < N; i++){
        cout << B[i] << " \n"[N == i - 1];
    }
}