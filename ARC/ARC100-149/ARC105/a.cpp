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
    vector<int> V(4);
    for(int i = 0; i < 4; i++) cin >> V[i];

    bool flag = false;
    for(int bit = 0; bit < (1 << 4); bit++){
        int eat = 0, remain = 0;
        for(int i = 0; i < 4; i++){
            if((bit >> i) & 1) eat += V[i];
            else remain += V[i];
        }

        if(remain == eat) flag = true;
    }

    cout << (flag ? "Yes" : "No") << endl;
}