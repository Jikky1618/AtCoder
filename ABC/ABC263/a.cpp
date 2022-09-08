#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    vector<int> in(13);
    for(int i = 0; i < 5; i++){
        int num;
        cin >> num;
        in[num]++;
    }
    
    for(int i = 0; i < 13; i++){
        if(in[i] == 1 || in[i] == 4 || in[i] == 5){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}