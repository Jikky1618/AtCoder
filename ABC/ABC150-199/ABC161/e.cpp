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
    int N, K, C;
    cin >> N >> K >> C;
    string S;
    cin >> S;

    vector<int> L, R;
    int pos = -INF;
    for(int i = 0; i < N; i++){
        if(S[i] == 'o' && pos + C + 1 <= i){
            L.emplace_back(i);
            pos = i;
        }
        if((int)L.size() == K) break;
    }

    pos = INF;
    for(int i = N - 1; i >= 0; i--){
        if(S[i] == 'o' && i <= pos - C - 1){
            R.emplace_back(i);
            pos = i;
        }
        if((int)R.size() == K) break;
    }

    reverse(R.begin(), R.end());

    for(int i = 0; i < K; i++){
        if(L[i] == R[i]){
            cout << L[i] + 1 << endl;
        }
    }
}