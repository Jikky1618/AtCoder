#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const ll INF = 1LL << 60;
const int MAX = 1e5 + 1;

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	int N;
	cin >> N;
	vector<int> T(N), X(N), A(N);
	for(int i = 0; i < N; i++) cin >> T[i] >> X[i] >> A[i];

	// 時間基準にする
	vector<pair<int, int>> p(MAX);
	for(int i = 0; i < N; i++){
		p[T[i]] = {X[i], A[i]};
	}

	// dp[i][j] := 時刻iに座標jにいるときの大きさの合計の最大値
	vector dp(MAX + 1, vector<ll>(5, -INF));
	dp[0][0] = 0;

	for(int i = 0; i < MAX; i++){
		dp[i][p[i].first] += p[i].second;
		for(int j = 0; j < 5; j++){
			if(0 < j) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - 1]);
			if(j < 4) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j + 1]);
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
		}
	}

	ll ans = *max_element(dp[MAX].begin(), dp[MAX].end());
	cout << ans << endl;
}