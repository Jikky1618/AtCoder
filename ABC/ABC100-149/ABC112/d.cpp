#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

    auto div = make_is_divisors(M);
    int Ans = 0;
    for(auto i: div){
        if(i <= (M / N)) Ans = i;
    }

    cout << Ans << endl;
    return 0;
}