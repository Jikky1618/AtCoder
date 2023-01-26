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
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    map<string, int> mp;
    for(int i = 0; i < N; i++){
        mp[S[i]]++;
    }

    string ans;
    int Max = -1;
    for(auto&& [key, val]: mp){
        if(Max < val){
            Max = val;
            ans = key;
        }
    }

    cout << ans << endl;
}