#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,res = 0;
    cin >> n;
    vector<int> d(n);
    for(int i = 0; i < n; i++) cin >> d[i];
    vector<int> num(101);
    for(int i = 0; i < n; i++){
        num[d[i]]++;
    }
    for(int i = 0; i < 101; i++){
        if(num[i] > 0){
            res++;
        }
    }
    cout << res << endl;
    
    return 0;
}