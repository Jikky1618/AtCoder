#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

template<class T>
T binomial(ll n, ll r){
    T res = 1;
    r = min(r, n - r);
    for(int i = 0; i < r; i++){
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int A, B;
    ll K;
    cin >> A >> B >> K;

    ll cnt = 0; // cnt := 文字列ansが最低でも辞書順でcnt番目以上
    string ans = "";
    while(A + B > 0){
        if(A == 0){
            ans += 'b';
            B--;
            continue;
        }
        if(B == 0){
            ans += 'a';
            A--;
            continue;
        }

        // 仮に次の文字をaとしたときの場合の数
        ll next = binomial<ll>(A + B - 1, B);
        debug(next, cnt + next);
        if(cnt + next < K){
            ans += 'b';
            B--;
            cnt += next; // aとしたときの場合の数より辞書順は後
        }else{
            ans += 'a';
            A--;
        }
    }

    cout << ans << endl;
}