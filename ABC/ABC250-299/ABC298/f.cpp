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
vector<T> compress(vector<T>& v){
    int n = v.size();
    vector<T> res = v;
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    for(int i = 0; i < n; i++){
        v[i] = lower_bound(res.begin(), res.end(), v[i]) - res.begin();
    }
    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> r(N), c(N), x(N);
    for(int i = 0; i < N; i++) cin >> r[i] >> c[i] >> x[i];

    compress(r);
    compress(c);

    // row[i] = {i番目に多い行の総和, id行目}, col[i] = {i番目に多いi列の総和, id列目}
    vector row(N, pair<ll, int>(0LL, -1)), col(N, pair<ll, int>(0LL, -1));

    // mp[{r, c}] := r行目, c列目の整数の値x[i]
    map<pair<int, int>, ll> mp;

    // 全ての整数をrow, col, mpに記録する
    for(int i = 0; i < N; i++){
        row[r[i]].first += x[i];
        row[r[i]].second = r[i];
        col[c[i]].first += x[i];
        col[c[i]].second = c[i];
        mp[{r[i], c[i]}] = x[i];
    }

    sort(col.begin(), col.end(), greater<pair<ll, int>>());

    ll ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            auto [x1, i1] = row[i];
            auto [x2, i2] = col[j];
            ll val = x1 + x2;
            if(mp.count({i1, i2})){
                val -= mp[{i1, i2}];
                ans = max(ans, val);
            }else{
                // colが昇順にソートされているのでbreakしても良い
                ans = max(ans, val);
                break;
            }
        }
    }

    cout << ans << endl;
}