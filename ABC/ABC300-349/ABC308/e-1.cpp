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
    string S;
    cin >> S;

    ll ans = 0;
    // M のカウント, ME のカウント
    map<int, ll> mp1;
    map<pair<int, int>, ll> mp2;
    for(int i = 0; i < N; i++){
        if(S[i] == 'M'){
            mp1[A[i]]++;
        }
        if(S[i] == 'E'){
            for(int j = 0; j < 3; j++){
                if(mp1[j] != 0){
                    mp2[{j, A[i]}] += mp1[j];
                }
            }
        }
        if(S[i] == 'X'){
            for(auto [key, val]: mp2){
                int mex = 0;
                auto [a, b] = key;
                for(int j = 0; j <= 3; j++){
                    if(A[i] != j && a != j && b != j){
                        mex = j;
                        break;
                    }
                }
                ans += val * mex;
            }
        }
        debug(mp1, mp2);
    }

    cout << ans << endl;
}