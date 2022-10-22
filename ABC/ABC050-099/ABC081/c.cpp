#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> bucket(n + 1);
    for(int i = 0; i < n; i++){
        bucket[a[i]]++;
    }
    sort(bucket.begin(), bucket.end());

    set<int> st;
    for(int i = 0; i < n; i++) st.insert(a[i]);

    int ans = 0;
    int cnt = st.size();
    for(int i = 0; i < n; i++){
        if(cnt <= k) break;
        if(0 < bucket[i]){
            ans += bucket[i];
            cnt--;
        }
    }

    cout << ans << endl;
    return 0;
}