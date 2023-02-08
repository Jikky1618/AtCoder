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
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    
    vector<vector<int>> C(200, vector<int>(0));
    // 高々201通りを全探索
    for(int bit = 0; bit < (1 << min(N, 8)); bit++){
        vector<int> B;
        int M = 0;
        for(int i = 0; i < min(N, 8); i++){
            if((bit >> i) & 1) B.push_back(i + 1), M = (M + A[i]) % 200;
        }
        if(C[M] != vector<int>(0)){
            cout << "Yes" << endl;
            cout << B.size() << " ";
            for(auto b: B){
                cout << b << " ";
            }
            cout << endl;
            cout << C[M].size() << " ";
            for(auto c: C[M]){
                cout << c << " ";
            }
            cout << endl;
            return 0;
        }else{
            C[M] = B;
        }
    }

    cout << "No" << endl;
}