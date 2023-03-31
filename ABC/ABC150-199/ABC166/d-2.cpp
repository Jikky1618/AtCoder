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
	ll X;
	cin >> X;

	map<ll, ll> mp; // val^5 = key
	// Bのありえる範囲は-200~200
	for(ll i = -200; i <= 200; i++){
		mp[i * i * i * i * i] = i;
	}

	// {B^5, B}の値を全探索
	for(auto [B5, B]: mp){
		if(mp.count(X + B5)){
			ll A = mp[X + B5]; // A^5 = X + B^5
			cout << A << " " << B << endl;
			return 0;
		}
	}
}