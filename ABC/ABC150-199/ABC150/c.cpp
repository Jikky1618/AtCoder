#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> p(n),q(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) cin >> q[i];

    vector<int> r;
    for(int i = 1; i <= n; i++) r.push_back(i);
    int a = -1, b = -1,cnt = 1;
    do{
        bool found_p = true, found_q = true;
        for(int i = 0; i < n; i++){
            if(p[i] != r[i]) found_p = false;
        }
        for(int i = 0; i < n; i++){
            if(q[i] != r[i]) found_q = false;
        }
        if(found_p) a = cnt;
        if(found_q) b = cnt;
        cnt++;
    }while(next_permutation(r.begin(),r.end()));
    int ans = abs(a - b);

    cout << ans << endl;
    return 0;
}