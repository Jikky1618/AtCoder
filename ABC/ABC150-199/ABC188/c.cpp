#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(1 << n);
    for(int i = 0; i < (1 << n); i++) cin >> a[i];

    int half = 1 << (n - 1);
    int Max1 = 0, Max2 = 0, Max = -1;
    for(int i = 0; i < (1 << n) - half; i++){
        if(a[i] > Max){
            Max = a[i];
            Max1 = i;
        }
    }
    Max = -1;
    for(int i = half; i < (1 << n); i++){
        if(a[i] > Max){
            Max = a[i];
            Max2 = i;
        }
    }

    int ans = a[Max1] > a[Max2] ? Max2 + 1 : Max1 + 1;
    cout << ans << endl;
    return 0;
}