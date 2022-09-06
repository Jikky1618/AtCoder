#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> flag(2100);
    for(int i = 0; i < n; i++) flag[a[i]]++;
    for(int i = 0; i < 2100; i++){
        if(flag[i] == 0){
            cout << i << endl;
            break;
        }
    }

    return 0;
}