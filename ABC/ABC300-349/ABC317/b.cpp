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

    sort(A.begin(), A.end());

    int m = *min_element(A.begin(), A.end());
    for(int i = 0; i < N + 1; i++){
        bool find = false;
        for(int j = 0; j < N; j++){
            if(A[j] == m + i){
                find = true;
                break;
            }
        }

        if(find == false){
            cout << m + i << endl;
            return 0;
        }
    }
}