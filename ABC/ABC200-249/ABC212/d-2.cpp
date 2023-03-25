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
	int Q;
	cin >> Q;

	priority_queue<ll, vector<ll>, greater<ll>> pq;
	ll sum = 0;
	while(Q--){
		int type; cin >> type;
		if(type == 1){
			int X; cin >> X;
			pq.push(X - sum);
		}
		if(type == 2){
			int X; cin >> X;
			sum += X;
		}
		if(type == 3){
			cout << pq.top() + sum << endl;
			pq.pop();
		}
	}
}