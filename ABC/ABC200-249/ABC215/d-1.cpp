#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const int MAX = 1e5 + 1;

vector<ll> make_is_divisors(ll x){
    vector<ll> divisors;
    for(ll i = 1; i * i <= x; i++){
        if(x % i == 0){
            divisors.push_back(i);
            // 重複しないならば i の相方である x/i も push
            if(x / i != i) divisors.push_back(x / i);
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<int> flag(MAX, true);
    for(int i = 0; i < N; i++){
        auto div = make_is_divisors(A[i]);
        for(auto e: div){
            if(e == 1) continue;
            if(flag[e] == false) continue;
            for(int j = e; j <= M; j += e){
                flag[j] = false;
            }
        }
    }

    int cnt = 0;
    for(int i = 1; i <= M; i++){
        if(flag[i]) cnt++;
    }

    cout << cnt << endl;
    for(int i = 1; i <= M; i++){
        if(flag[i]) cout << i << endl;
    }
}