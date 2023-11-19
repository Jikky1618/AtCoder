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
    string S;
    cin >> N >> S;
    // 各文字で最大の同じ区間の長さ
    vector<int> cnt(26);
    for(int left = 0, right = 0; left < N; left++){
        while(right < N && S[right] == S[left]) right++;
        // [left, right) が連続した同じ文字の区間
        cnt[S[left] - 'a'] = max(cnt[S[left] - 'a'], right - left);
        if(left == right) right++;
    }
    int ans = reduce(cnt.begin(), cnt.end(), 0);
    cout << ans << endl;
}