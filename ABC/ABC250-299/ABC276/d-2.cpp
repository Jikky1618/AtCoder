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
    vector<int> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];

    vector<int> d2(N), d3(N);
    for(int i = 0; i < N; i++){
        while(a[i] % 2 == 0){
            a[i] /= 2;
            d2[i]++;
        }
        while(a[i] % 3 == 0){
            a[i] /= 3;
            d3[i]++;
        }
    }

    bool flag = false;
    for(int i = 0; i < N; i++) if(a[i] != a[0]) flag = true;

    if(flag){
        cout << -1 << endl;
        return 0;
    }

    int m2 = *min_element(d2.begin(), d2.end()), m3 = *min_element(d3.begin(), d3.end());

    ll ans = 0;
    for(int i = 0; i < N; i++) ans += (d2[i] - m2) + (d3[i] - m3);

    cout << ans << endl;
}