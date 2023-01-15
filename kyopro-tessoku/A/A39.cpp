#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<pair<int, int>> T(N);
    for(int i = 0; i < N; i++){
        int L, R; cin >> L >> R;
        T[i].first = L, T[i].second = R;
    }

    sort(T.begin(), T.end(), [&](auto &l, auto &r){
        return l.second < r.second;
        });

    int ans = 0, time = 0;
    for(int i = 0; i < N; i++){
        if(time <= T[i].first){
            ans++;
            time = T[i].second;
        }
    }

    cout << ans << endl;
}