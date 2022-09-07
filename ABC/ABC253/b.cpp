#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    for(int i = 0; i < h; i++) cin >> s[i];

    int x1,y1,x2,y2;
    bool find1 = false;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(s[i][j] == 'o'){
                if(!find1){
                    y1 = i; x1 = j;
                    find1 = true;
                }else{
                    y2 = i; x2 = j;
                }
            }
        }
    }

    cout << abs(x1 - x2) + abs(y1 - y2) << endl;

    return 0;
}