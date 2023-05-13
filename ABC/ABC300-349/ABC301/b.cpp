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

    vector<int> ans;
    for(int i = 0; i < N - 1; i++){
        ans.emplace_back(A[i]);
        if(abs(A[i] - A[i + 1]) == 1) continue;

        if(A[i] > A[i + 1]){
            for(int j = A[i] - 1; j > A[i + 1]; j--) ans.emplace_back(j);
        }else{
            for(int j = A[i] + 1; j < A[i + 1]; j++) ans.emplace_back(j);
        }
    }
    ans.emplace_back(A.back());

    int M = ans.size();
    for(int i = 0; i < M; i++){
        cout << ans[i] << " \n"[i == M - 1];
    }
}