#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<pair<int, string>> data(n);
    for(int i = 0; i < n; i++) cin >> data[i].second >> data[i].first;
    // sort(a.begin(), a.end(), greater< int >()); 
    sort(data.begin(), data.end());
    reverse(data.begin(), data.end());

    cout << data[1].second << endl; 

    return 0;
}