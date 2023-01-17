#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, K;
    cin >> N >> K;
    vector<int> V(N);
    for(int i = 0; i < N; i++) cin >> V[i];

    int ans = 0;
    for(int a = 0; a <= min(K, N); a++){
        for(int b = 0; a + b <= min(K, N); b++){
            vector<int> val;
            for(int i = 0; i < a; i++) val.push_back(V[i]);
            for(int i = 0; i < b; i++) val.push_back(V[N - 1 - i]);
            sort(val.begin(), val.end());

            int sum = 0;
            for(auto&& v: val) sum += v;
            for(int i = 0; i < min(K - (a + b), (int)val.size()); i++){
                if(val[i] < 0) sum -= val[i];
            }

            ans = max(ans, sum);
        }
    }

    cout << ans << endl;
}