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
    vector<int> P(N), Q(N);
    for(int i = 0; i < N; i++) cin >> P[i];
    for(int i = 0; i < N; i++) cin >> Q[i];


    vector<int> p(N);
    iota(p.begin(), p.end(), 1); // 1, 2, ..., N

    int a = 0, b = 0, cnt = 0;
    do{
        bool flag_P = true, flag_Q = true;
        for(int i = 0; i < N; i++){
            if(p[i] != P[i]) flag_P = false;
            if(p[i] != Q[i]) flag_Q = false;
        }

        if(flag_P) a = cnt;
        if(flag_Q) b = cnt;

        cnt++;
    }while(next_permutation(p.begin(), p.end()));

    cout << abs(a - b) << endl;
}