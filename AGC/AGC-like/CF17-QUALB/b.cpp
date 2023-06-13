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
    vector<int> D(N);
    for(int i = 0; i < N; i++) cin >> D[i];
    int M;
    cin >> M;
    vector<int> T(M);
    for(int i = 0; i < M; i++) cin >> T[i];

    map<int, int> cnt1, cnt2;
    for(int i = 0; i < N; i++) cnt1[D[i]]++;
    for(int i = 0; i < M; i++) cnt2[T[i]]++;

    bool flag = true;
    for(auto&& [key, val]: cnt2){
        if(cnt1[key] < val) flag = false;
    }

    cout << (flag ? "YES" : "NO") << endl;
}