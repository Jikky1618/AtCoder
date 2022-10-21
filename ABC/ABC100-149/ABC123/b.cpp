#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    vector<int> a(5);
    for(int i = 0; i < 5; i++) cin >> a[i];

    int ans = INF;
    sort(a.begin(), a.end());
    do{
        int time = 0;
        for(int i = 0; i < 5; i++){
            time += a[i];
            if(i != 4) time += (10 - a[i] % 10 == 10) ? 0 : (10 - a[i] % 10);
        }
        ans = min(ans, time);
    }while(next_permutation(a.begin(), a.end()));

    cout << ans << endl;
}