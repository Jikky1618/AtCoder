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
    string S;
    cin >> N >> S;

    bool flag = (count(S.begin(), S.end(), '-') && count(S.begin(), S.end(), 'o'));

    int ans = 0, val = 0;
    for(auto c: S){
        if(c == 'o'){
            val++;
            ans = max(ans, val);
        }else{
            val = 0;
        }
    }

    cout << (flag ? ans : -1) << endl;
}