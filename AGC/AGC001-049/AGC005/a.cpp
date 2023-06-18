#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

void gen_case(string &X){
    int64_t seed = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
    mt19937_64 rnd(seed);

    uniform_int_distribution<int> dist_size(2, 200), dist_S(0, 1);
    int N = dist_size(rnd);

    X = "";
    for(int i = 0; i < N; i++){
        X += (dist_S(rnd) ? 'T' : 'S');
    }
}

int naive(string X){
    assert(X.size() <= 210);
    while(true){
        int N = X.size();
        bool flag = false;
        for(int i = 0; i < N - 1; i++){
            if(X[i] == 'S' && X[i + 1] == 'T'){
                X.erase(i, 2);
                flag = true;
                break;
            }
        }
        if(!flag || N == 0) break;
    }

    return X.size();
}

int solve(string X){
    int N = X.size();
    int cnt_S = 0, cnt_T = 0;
    for(int i = N - 1; i >= 0; i--){
        if(X[i] == 'T') cnt_T++;
        if(X[i] == 'S' && cnt_T > 0) cnt_S++, cnt_T--;
    }

    int ans = N - cnt_S * 2;
    return ans;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string X;
    cin >> X;
    cout << solve(X) << endl;
}