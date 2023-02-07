#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

vector<bool> make_is_prime(ll x){
    vector<bool> prime(x + 1, true);
    prime[0] = prime[1] = false;
    for(int i = 2; i * i <= x; i++){
        if(!prime[i]) continue;
        for(int j = i * 2; j <= x; j += i){
            prime[j] = false;
        }
    }
    return prime;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;

    auto p = make_is_prime(55555);
    vector<int> A;
    int cnt = 0;
    for(int i = 0; i <= 55555; i++){
        if(p[i] && i % 5 == 1){
            A.push_back(i);
            cnt++;
        } 
        if(cnt  == N) break;
    }

    for(auto a: A){
        cout << a << " ";
    }
    cout << endl;
}