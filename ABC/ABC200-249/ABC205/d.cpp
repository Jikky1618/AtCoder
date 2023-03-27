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
	int N, Q;
	cin >> N >> Q;
	vector<ll> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];

	auto check = [&](ll mid, ll K) -> bool {
		ll pos = lower_bound(A.begin(), A.end(), mid) - A.begin();
		return mid - pos - 1 <= K;
	};

	while(Q--){
		ll K; cin >> K, K--;
		ll left = -1, right = 2e18 + 1;
		while(right - left > 1){
			ll mid = (left + right) / 2;
			if(check(mid, K)) left = mid;
			else right = mid;
		}
		cout << left << "\n";
	}
}