#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int res = 0;
    while(true){
        bool flag = false;
        for(int i = 0; i < n; i++){
            if(a[i] % 2 == 1) flag = true;
        }
        if(flag) break;
        for(int i = 0; i < n; i++){
            a[i] /= 2;
        }
        res++;
    }
    cout << res << endl;

    return 0;
}