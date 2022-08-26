#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i + 1;
    };

    sort(a.begin(), a.end(),greater<pair<int,int>>());

    cout << a[1].second <<endl;

    return 0;
}