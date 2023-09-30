#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

bool is_palindrome(const string& s){
    return equal(s.begin(), s.end(), s.rbegin());
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin >> S;

    int N = S.size();
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            string T = "";
            for(int k = i; k <= j; k++){
                T += S[k];
            }
            debug(T);
            if(is_palindrome(T)) ans = max(ans, j - i + 1);
        }
    }

    cout << ans << endl;
}