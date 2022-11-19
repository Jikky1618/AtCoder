#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int m;
    cin >> m;
    vector<int> b(m);
    for(int i = 0; i < m; i++) cin >> b[i];

    int score = 0;
    for(int i = 0; i < n; i++){
        score += a[i];
        if(count(b.begin(), b.end(), score)) score = 0;
    }

    cout << score << endl;
    return 0;
}