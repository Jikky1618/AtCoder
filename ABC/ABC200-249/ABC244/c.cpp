#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<bool> num(2 * n + 10);

    while(1){
        int out = 1;
        for(int i = 1; i <= 2 * n + 1; i++){
            if(!num[i]){
                out = i;
                cout << out << endl;
                num[out] = true;
                break;
            }
        }
        int in;
        cin >> in;
        if(in == 0) break;
        num[in] = true;
    }

    return 0;
}