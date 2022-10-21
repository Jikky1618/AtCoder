#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    vector<int> a(5);
    for(int i = 0; i < 5; i++) cin >> a[i];
    int k;
    cin >> k;

    bool flag = true;
    for(int i = 0; i < 5; i++){
        for(int j = i + 1; j < 5; j++){
            if(a[j] - a[i] > k) flag = false;
        }
    }

    if(flag) cout << "Yay!" << endl;
    else cout << ":(" << endl;
    return 0;
}