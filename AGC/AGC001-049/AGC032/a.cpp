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
    vector<int> B(N);
    for(int i = 0; i < N; i++) cin >> B[i];

    vector<int> ans;
    // 逆操作をして, 空の数列にできるかを判定
    for(int i = 0; i < N; i++){
        for(int j = (int)B.size() - 1; j >= 0; j--){
            if(B[j] == j + 1){
                ans.emplace_back(B[j]);
                B.erase(B.begin() + j);
                break;
            }
        }
    }

    if(B.size() == 0){
        reverse(ans.begin(), ans.end());
        for(auto e: ans){
            cout << e << endl;
        }
    }else{
        cout << -1 << endl;
    }
}