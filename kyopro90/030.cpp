#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

vector<int> eratosthenes(const int x){
    vector<bool> prime(x + 1, true);
    prime[0] = prime[1] = false;
    for(int i = 2; i * i <= x; i++){
        if(!prime[i]) continue;
        for(int j = i * 2; j <= x; j += i){
            prime[j] = false;
        }
    }

    vector<int> res;
    for(int i = 2; i <= x; i++){
        if(prime[i]) res.emplace_back(i);
    }
    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, K;
    cin >> N >> K;

    vector<int> num(N + 1);
    for(auto&& p: eratosthenes(N)){
        for(int i = p; i <= N; i += p){
            num[i]++;
        }
    }
    
    int ans = 0;
    for(int i = 0; i <= N; i++){
        if(K <= num[i]) ans++;
    }

    cout << ans << endl;
}