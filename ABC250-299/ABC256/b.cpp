#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int p = 0;
    vector<int> field(4);
    for(int i = 0; i < n; i++){
        field[0]++;
        for(int j = 3; j >= 0; j--){
            if(field[j] == 1){
                if(j + a[i] < 4) field[j + a[i]]++;
                else p++;
                field[j] = 0;
            }
        }
    }
    cout << p << endl;
    return 0;
}