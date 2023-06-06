#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

vector<pair<char, ll>> rle(const string& s){
    int n = s.size();
    vector<pair<char, ll>> res;
    ll cnt = 1;
    for(int i = 0; i < n; i++){
        if (i == n - 1 || s[i] != s[i + 1]){
            res.push_back({s[i], cnt});
            cnt = 1;
        }
        else cnt++;
    }
    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    ll K;
    cin >> S >> K;

    // corner case: K = 1
    if(K == 1){
        auto PS = rle(S);
        ll cnt = 0;
        for(auto [c, val]: PS){
            cnt += val / 2;
        }
        cout << cnt << endl;
        return 0;
    }
    // corner case: 使用している文字数が1
    set<char> st;
    for(auto c: S) st.insert(c);
    if(st.size() == 1){
        auto PS = rle(S);
        ll val = PS.front().second;
        ll cnt = val * K / 2;
        cout << cnt << endl;
        return 0;
    }

    char last = S.back();
    // 先頭の例外を処理 (S + 最後の文字のグループ)
    string A = S;
    for(auto c: S){
        if(c == last) A += c;
        else break;
    }

    // 中盤は全てB(Sから先頭の文字グループを削除 + 最後の文字グループ)
    string B = S;
    for(auto c: S){
        if(c == last) B.erase(B.begin());
        else break;
    }
    for(auto c: S){
        if(c == last) B += c;
        else break;
    }

    // 末尾の例外を処理(Sから最初の文字グループを削除)
    string C = S;
    for(auto c: S){
        if(c == last) C.erase(C.begin());
        else break;
    }

    auto PA = rle(A), PB = rle(B), PC = rle(C);
    debug(PA, PB, PC);
    ll cntA = 0, cntB = 0, cntC = 0;
    for(auto [c, val]: PA) cntA += val / 2;
    for(auto [c, val]: PB) cntB += val / 2;
    for(auto [c, val]: PC) cntC += val / 2;

    debug(cntA, cntB, cntC);
    ll ans = cntA + (cntB * (K - 2)) + cntC;
    cout << ans << endl;
}