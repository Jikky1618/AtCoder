#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool win(char a,char b){
    if(a == 'G' && b == 'C') return true;
    if(a == 'C' && b == 'P') return true;
    if(a == 'P' && b == 'G') return true;
    return false;
}
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n,m;
    cin >> n >> m;
    vector<string> a(2 * n);
    for(int i = 0; i < 2 * n; i++) cin >> a[i];

    // wp[i].first := 勝数 wp[i].second := 人i
    vector<pair<int,int>> wp(2 * n);
    for(int i = 0; i < 2 * n; i++) wp[i].second = i;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int p1 = wp[j * 2].second, p2 = wp[j * 2 + 1].second;
            if(win(a[p1][i],a[p2][i])) wp[j * 2].first--;
            if(win(a[p2][i],a[p1][i])) wp[j * 2 + 1].first--;
        }
        sort(wp.begin(), wp.end());
    }

    for(auto &&i: wp) cout << i.second + 1 << endl;
    return 0;
}