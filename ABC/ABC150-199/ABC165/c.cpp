#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n,m,q;
vector<int> a(q),b(q),c(q),d(q);
vector<int> A(10);
int ans = 0;
// cnt: 何回目の再帰関数か。
// last: A[cnt] の要素はなにか。
void dfs(int cnt = 0, int last = 1){
    if(cnt == n){
        int sum = 0;
        for(int i = 0; i < q; i++){
            if(A[b[i] - 1] - A[a[i] - 1] == c[i]) sum += d[i];
        }
        ans = max(ans, sum);
        return;
    }
    for(int i = last; i <= m; i++){
        A[cnt] = i;
        dfs(cnt + 1, i);
    }
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    a.resize(q); b.resize(q); c.resize(q); d.resize(q);
    for(int i = 0; i < q; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
    dfs();
    cout << ans << endl;
    return 0;
}