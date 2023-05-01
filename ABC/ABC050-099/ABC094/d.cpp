#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

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

    sort(A.begin(), A.end(), greater<int>());
    
    // 最大の組comb(n, r)は n = Amax, r = n / 2に最も近い値のとき
    int r = -1, diff = INF;
    for(int i = 1; i < N; i++){
        int val = abs(A[i] - A[0] / 2);
        if(val < diff){
            diff = val, r = A[i];
        }
    }

    cout << A[0] << " " << r << endl;
}