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
    cin >> N; 
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    int cnt = count(S.begin(), S.end(), "For");

    cout << (N / 2 < cnt ? "Yes" : "No") << endl;
}