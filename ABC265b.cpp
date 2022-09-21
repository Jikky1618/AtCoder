#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n, m, t;
    cin >> n >> m >> t;
    vector<int> a(n);
    for(int i = 0; i < n - 2; i++) cin >> a[i];
    vector<int> x(m);
    vector<int> y(m);
    for(int i = 0; i < m; i++) cin >> x[i] >> y[i];
 
    for(int i = 0,j = 0; i < n - 2; i++){
        if(t <= 0){
            cout << "No" << endl;
            return 0;
        }
        if(i == x[j] - 1){
            t += y[j];
            j++;
        }
        t -= a[i];
    }

    cout << "Yes" << endl;
    return 0;
}