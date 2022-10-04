#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<tuple<string,int,int>> p(n);
    for(int i = 0; i < n; i++){
        string name;
        int point;
        cin >> name >> point;
        get<0>(p[i]) = name;
        get<1>(p[i]) = 100 - point;
        get<2>(p[i]) = i + 1;
    }
    sort(p.begin(), p.end());
    for(int i = 0; i < n; i++){
        cout << get<2>(p[i]) << endl;
    }

    return 0;
}