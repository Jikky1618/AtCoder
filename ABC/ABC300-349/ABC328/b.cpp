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
    vector<int> D(N);
    for(int i = 0; i < N; i++) cin >> D[i];

    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < D[i]; j++){
            string S = to_string(i + 1) + to_string(j + 1);
            set<char> st;
            for(auto c: S) st.insert(c);
            if(st.size() == 1) ans++;
        }
    }

    cout << ans << endl;
}