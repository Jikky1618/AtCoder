#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    deque<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = 0, cnt = 0;
    while(!a.empty()){
        int num = a.front(); a.pop_front();
        if(num == cnt){
            cnt++;
        }else{
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}