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

    vector<int> cnt(N + 1);
    for(int i = N; i > 0; i--){
        int sum = 0;
        for(int j = i * 2; j <= N; j += i) sum += cnt[j];
        if(sum % 2 != A[i - 1]) cnt[i] = 1;
    }

    vector<int> ans;
    for(int i = 1; i <= N; i++){
        if(cnt[i]) ans.emplace_back(i);
    }

    int M = ans.size();
    cout << M << "\n";
    for(int i = 0; i < M; i++){
        cout << ans[i] << " \n"[i == M - 1];
    }
}