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
    int ans = 0;
    for(int i = 0; i < N; i++){
        char c = (i % 2 == 0 ? 'g' : 'p');
        if(S[i] == 'g' && c == 'p') ans++;
        if(S[i] == 'p' && c == 'g') ans--;
    }

    cout << ans << endl;
}