#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<pair<int,int>> P(n);
    for(int i = 0; i < n; i++) cin >> P[i].first >> P[i].second;

    sort(P.begin(), P.end());
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            // 右上、右下を全探索
            auto a = P[i], b = P[j];
            if(a.first < b.first && a.second < b.second){
                if(binary_search(P.begin(), P.end(), pair<int,int>(a.first, b.second)) && binary_search(P.begin(), P.end(), pair<int,int>(b.first, a.second))){
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}