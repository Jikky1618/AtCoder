#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    string s;
    cin >> n >> s;

    char dir = 'E';
    int x = 0,y = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'S'){
            if(dir == 'E') x++;
            else if(dir == 'S') y--;
            else if(dir == 'W') x--;
            else if(dir == 'N') y++;
        }else if(s[i] == 'R'){
            if(dir == 'E') dir = 'S';
            else if(dir == 'S') dir = 'W';
            else if(dir == 'W') dir = 'N';
            else if(dir == 'N') dir = 'E';
        }
    }

    cout << x << " " << y << endl;

    return 0;
}