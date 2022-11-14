#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    // p[[y,x]][i] := i番目の点、(x,y)
    vector<pair<pair<int,int>,int>> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i].first.second >> p[i].first.first;
        p[i].second = i;
    }
    string s;
    cin >> s;

    sort(p.begin(), p.end());
    bool flag = false;
    for(int i = 0; i < n - 1; i++){
        // y座標が一致
        if(p[i].first.first == p[i+1].first.first){
            if(p[i].first.second < p[i+1].first.second && s[p[i].second] == 'R' && s[p[i+1].second] == 'L'){
                flag = true;
            }
            if(p[i].first.second > p[i+1].first.second && s[p[i].second] == 'L' && s[p[i+1].second] == 'R'){
                flag = true;
            }
        }
        if(flag){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}