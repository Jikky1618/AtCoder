#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

template<class T, class U>
T floor(T x, U y){
    return (x ? x / y : (x + y - 1) / y);
}

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	ll A, B, N;
	cin >> A >> B >> N;

	auto f = [&](ll x) -> ll {
		ll res = floor(A * x, B) - A * floor(x, B);
		return res;
	};

	if(B <= N){
		cout << f(B - 1) << endl;
	}else{
		cout << f(N) << endl;
	}
}