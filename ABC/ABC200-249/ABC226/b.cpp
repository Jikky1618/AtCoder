#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    set<vector<int>> seq;
    for(int i = 0; i < n; i++){
        int l;
        cin >> l;
        vector<int> v(l);
        for(int j = 0; j < l; j++) cin >> v[j];
        seq.insert(v);
    }

    cout << seq.size() << endl;
    
    return 0;
}