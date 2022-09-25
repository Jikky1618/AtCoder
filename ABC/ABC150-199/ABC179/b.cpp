#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int,int>> d(n);
    for(int i = 0; i < n; i++){
        cin >> d[i].first >> d[i].second;
    }

    int zoro = 0;
    for(int i = 0; i < n; i++){
        if(d[i].first == d[i].second) zoro++;
        else zoro = 0;
        if(zoro == 3){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}