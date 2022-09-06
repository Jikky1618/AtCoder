#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    string s;
    cin >> n >> s;

    int dir = 0;
    int x = 0,y = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'S'){
            if(dir == 0) x++;
            if(dir == 1) y--;
            if(dir == 2) x--;
            if(dir == 3) y++;
        }else if(s[i] == 'R'){
            dir = (dir + 1) % 4;
        }
    }

    cout << x << " " << y << endl;

    return 0;
}