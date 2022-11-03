#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<int> x(n),y(n);
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];

    set<pair<int,int>> st;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            int dx = x[i] - x[j];
            int dy = y[i] - y[j];
            int g = gcd(dx, dy);
            st.insert(pair<int,int>(dx / g, dy / g));
        }
    }
    cout << st.size() << endl;
    return 0;
}