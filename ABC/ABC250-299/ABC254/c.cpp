#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];

    // 数列AをK個の数列に分ける
    vector<vector<int>> s(K);
    for(int i = 0; i < N; i++){
        s[i % K].push_back(a[i]);
    }

    // K個の数列を局所的にソート
    for(int i = 0; i < K; i++) sort(s[i].begin(), s[i].end(), greater<int>());

    // 配列ansにマージ
    vector<int> ans;
    for(int i = 0; i < N; i++){
        ans.push_back(s[i % K].back());
        s[i % K].pop_back();
    }

    sort(a.begin(), a.end());
    
    cout << (a == ans ? "Yes" : "No") << endl;
    return 0;
}