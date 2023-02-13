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
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    
    auto s = rle(S);
    // s[i]のi奇数: 連続する0の個数 
    // s[i]のi偶数: 連続する1の個数
    vector<int> numbers;
    if(S.front() == '0') numbers.push_back(0);
    for(auto [val, cnt]: s) numbers.push_back(cnt);
    if(S.back() == '0') numbers.push_back(0);

    int M = numbers.size();
    // 累積和
    vector<int> sums(M + 1);
    for(int i = 0; i < M; i++) sums[i + 1] = sums[i] + numbers[i];

    // 偶数番目から始まる連続する2K+1個(以下)の整数の和の最大値
    int ans = 0;
    int add = 2 * K + 1;
    for(int i = 0; i < M + 1; i += 2){
        int left = i, right = min(left + add, M);
        ans = max(ans, sums[right] - sums[left]);
    }

    cout << ans << endl;
}