#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N, A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;

    // 何回bの操作をするか
    auto str_count = [&](string S) -> ll {
        ll res = 0;
        for(int i = 0; i < N / 2; i++){
            if(S[i] != S[N - 1 - i]) res++;
        }
        return res;
    };

    ll ans = INF;
    for(ll i = 0; i < N; i++){
        ll val = i * A + str_count(S) * B;
        ans = min(ans, val);
        rotate(S.begin(), S.begin() + 1, S.end());
    }

    cout << ans << endl;
}