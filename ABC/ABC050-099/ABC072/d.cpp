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
    vector<int> p(N);
    for(int i = 0; i < N; i++) cin >> p[i];

    int ans = 0;
    for(int i = 0; i < N; i++){
        if(p[i] == i + 1){
            ans++;
            if(i + 1 < N) swap(p[i], p[i + 1]);
        }
    }

    cout << ans << endl;
}