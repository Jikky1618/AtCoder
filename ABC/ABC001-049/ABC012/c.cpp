#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;

    int sum = 0;
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            sum += i * j;
        }
    }

    int num = sum - n;
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            if(i * j == num) cout << i << " x " << j << endl;
        }
    }
    return 0;
}