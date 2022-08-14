#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> t(n + 1),x(n + 1),y(n + 1);
    t[0] = x[0] = y[0] = 0;
    for(int i = 0; i < n; i++) cin >> t[i + 1] >> x[i + 1] >> y[i + 1]; // 1-index

    bool can = true;
    for(int i = 0; i < n; i++){
        int dt = t[i + 1] - t[i];
        int dist = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);
        if(dt < dist) can = false;
        if(dt % 2 != dist % 2) can = false;  // Is the evenness of dist and dt equal?
    }
    if(can) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}