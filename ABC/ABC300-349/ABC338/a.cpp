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
    bool flag = true;
    if(islower(S.front())) flag = false;
    for(int i = 1; i < N; i++) if(isupper(S[i])) flag = false;

    cout << (flag ? "Yes" : "No") << '\n';
}