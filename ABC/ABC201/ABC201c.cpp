#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<long long int> mod(200);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mod[a[i] % 200]++;
    }
    long long int ans = 0;
    for(int j = 0; j < 200; j++){
        ans += mod[j] * (mod[j] - 1) / 2;
    }
    cout << ans << endl;

    return 0;
}