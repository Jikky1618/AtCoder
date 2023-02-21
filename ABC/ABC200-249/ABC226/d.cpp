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
    vector<int> x(N), y(N);
    for(int i = 0; i < N; i++) cin >> x[i] >> y[i];

    set<pair<int, int>> st;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j) continue;
            int dx = x[i] - x[j], dy = y[i] - y[j];
            int G = gcd(dx, dy);
            st.insert({dx / G, dy / G});
        }
    }

    cout << st.size() << endl;
}