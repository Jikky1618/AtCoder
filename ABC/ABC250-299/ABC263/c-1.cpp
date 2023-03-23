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

    vector<int> A;
    for(int i = 0; i < N; i++) A.push_back(0);
    for(int i = 0; i < M - N; i++) A.push_back(1);

    do{
        vector<int> ans;
        for(int i = 0; i < M; i++){
            if(A[i] == 0) ans.push_back(i + 1);
        }
        for(int i = 0; i < N; i++){
            cout << ans[i] << " \n"[i == N - 1];
        }
    }while(next_permutation(A.begin(), A.end()));
}