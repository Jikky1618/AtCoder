#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << "\033[33m[" << __LINE__ << "] " << #x << ": " << x << "\033[m" << endl;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    vector<pair<int,int>> p1;
    for(int x = x1 - 3; x <= x1 + 3; x++){
        for(int y = y1 - 3; y <= y1 + 3; y++){
            int diff = (x - x1) * (x - x1) + (y - y1) * (y - y1);
            if(diff == 5){
                p1.push_back(make_pair(x, y));
            }
        }
    }
    vector<pair<int,int>> p2;
    for(int x = x2 - 3; x <= x2 + 3; x++){
        for(int y = y2 - 3; y <= y2 + 3; y++){
            int diff = (x - x2) * (x - x2) + (y - y2) * (y - y2);
            if(diff == 5){
                p2.push_back(make_pair(x, y));
            }
        }
    }

    bool found = false;
    for(int i = 0; i < p1.size(); i++){
        for(int j = 0; j < p2.size(); j++){
            if(p1[i] == p2[j]){
                found = true;
                break;
            }
        }
    }

    if(found) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}