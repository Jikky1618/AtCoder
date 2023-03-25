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
	string S;
	cin >> S;

	int N = S.size();

    vector<int> cnt(10);
    map<vector<int>, ll> mp;
    mp[cnt]++; // 最初の要素も足す
    for(int i = 0; i < N; i++){
        // i番目のときの文字数のカウント
        cnt[S[i] - '0']++, cnt[S[i] - '0'] %= 2;
        mp[cnt]++;
    }

    ll ans = 0;
    for(auto [key, val]: mp){
        ans += val * (val - 1) / 2;
    }

	cout << ans << endl;
}