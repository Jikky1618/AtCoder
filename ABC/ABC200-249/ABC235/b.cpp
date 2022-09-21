#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];

    int i = 0;
    while(h[i] < h[i + 1]){
        i++;
    }

    cout << h[i] << endl;

    return 0;
}