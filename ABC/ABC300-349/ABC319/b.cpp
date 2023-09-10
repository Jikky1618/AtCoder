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

    string ans = "";
    for(int i = 0; i <= N; i++){
        bool found = false;
        for(int j = 1; j <= 9; j++){
            if(N % j == 0){
                if(i % (N / j) == 0){
                    ans += to_string(j);
                    found = true;
                    break;
                }
            }
        }
        if(!found) ans += "-";
    }
    
    cout << ans << endl;
}