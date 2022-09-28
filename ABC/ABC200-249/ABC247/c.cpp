#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(vector<int> &s,int num){
    if(num == 1){
        s.push_back(1);
    }else{
    dfs(s,num - 1);
    s.push_back(num);
    dfs(s,num - 1);
    }
}
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> ans;
    dfs(ans,n);

    for(auto i: ans){
        if(i != ans.size()) cout << i << " ";
        else cout << i << endl;
    }
    return 0;
}