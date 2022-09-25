#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int x,y;
    cin >> x >> y;

    bool flag = false;
    for(int turtle = 0; turtle <= x; turtle++){
        int crane = x - turtle;
        if(crane * 2 + turtle * 4 == y) flag = true;
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}