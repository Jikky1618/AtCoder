#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> cut;
    int angle = 0;
    // first cut
    cut.push_back(0);
    cut.push_back(360);

    for(int i = 0; i < n; i++){
        angle = (angle + a[i]) % 360;
        cut.push_back(angle);
    }
    sort(cut.begin(), cut.end());

    int max = 0;
    for(int i = 0; i < n + 1; i++){
        int diff = cut[i + 1] - cut[i];
        if(diff > max) max = diff;
    }

    cout << max << endl;
    
    return 0;
}