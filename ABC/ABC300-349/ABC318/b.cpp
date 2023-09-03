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
    vector<int> A(N), B(N), C(N), D(N);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];

    map<pair<int, int>, int> mp;
    for(int i = 0; i < N; i++){
        for(int x = A[i]; x < B[i]; x++){
            for(int y = C[i]; y < D[i]; y++){
                mp[{x, y}]++;
            }
        }
    }

    int ans = mp.size();
    cout << ans << endl;
}