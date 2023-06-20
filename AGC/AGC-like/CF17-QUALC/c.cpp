#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

bool is_palindrome(const string& s){
    return equal(s.begin(), s.end(), s.rbegin());
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin >> S;

    string T = "";
    for(auto c: S) if(c != 'x') T += c;

    // x を抜いた S が回分でなければ, 回分にはできない
    if(!is_palindrome(T)){
        cout << -1 << endl;
        return 0;
    }

    // x を抜いた文字の前後にある x の数をカウント
    int N = T.size() + 1;
    vector<int> cnt(N);
    int pos = 0;
    for(unsigned i = 0; i < S.size(); i++){
        if(S[i] != 'x') pos++;
        if(S[i] == 'x') cnt[pos]++;
    }

    int ans = 0;
    // 回分で x を挿入する最小限の数を計算する
    for(int i = 0; i < N / 2; i++){
        int diff = abs(cnt[i] - cnt[N - i - 1]);
        ans += diff;
    }

    cout << ans << endl;
}