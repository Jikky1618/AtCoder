#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> x(n),y(n);
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];

    bool flag = false;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if((y[i] - y[j]) * (x[i] - x[k]) == (x[i] - x[j]) * (y[i] - y[k])){
                    flag = true;
                    break;
                }
            }
        }
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}