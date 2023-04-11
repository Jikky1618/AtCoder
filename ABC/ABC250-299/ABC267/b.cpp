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

    if(S[0] == '1'){
        cout << "No" << endl;
        return 0;
    }

    vector<int> c(7);
    c[0] = (S[6] == '1');
    c[1] = (S[3] == '1');
    c[2] = (S[1] == '1' || S[7] == '1');
    c[3] = (S[0] == '1' || S[4] == '1');
    c[4] = (S[2] == '1' || S[8] == '1');
    c[5] = (S[5] == '1');
    c[6] = (S[9] == '1');

    for(int i = 0; i < 7; i++){
        for(int j = i + 2; j < 7; j++){
            // 列i, jが立っているとき
            if(c[i] && c[j]){
                bool flag = true;
                // 間の列が全て倒れているかを確認
                for(int k = i + 1; k < j; k++){
                    if(c[k] == 1) flag = false;
                }
                if(flag){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;
}