#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> num(n);
    for(int i = 0; i < n; i++) num[i] = i + 1;

    int ans = num[0], max = 0;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        int tmp = num[i];
        while( tmp% 2 == 0) tmp /= 2, cnt++;
        if(max < cnt) max = cnt, ans = num[i];
    }

    cout << ans << endl;
    return 0;
}