#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    vector<int> in(13);
    for(int i = 0; i < 5; i++){
        int num;
        cin >> num;
        in[num]++; // 各数字の出現回数
    }
    
    for(int i = 0; i < 13; i++){
        // フルハウスのとき、出現するカードの枚数は0,2,3枚
        if(in[i] == 1 || in[i] == 4 || in[i] == 5){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}