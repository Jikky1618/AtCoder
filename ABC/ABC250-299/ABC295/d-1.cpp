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

    vector<vector<int>> acc(N + 1, vector<int>(10));
	for(int i = 0; i < N; i++){
		for(int j = 0; j < 10; j++){
            acc[i + 1][j] = acc[i][j] + (S[i] == j + '0'), acc[i + 1][j] %= 2;
        }
	}

	ll ans = 0;
	map<vector<int>, int> mp;
	for(int i = 0; i <= N; i++){
		vector<int> V;
		for(int j = 0; j < 10; j++) V.push_back(acc[i][j]);
		ans += mp[V];
		mp[V]++;
	}

	cout << ans << endl;
}