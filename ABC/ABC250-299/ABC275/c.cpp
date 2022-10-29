#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

bool check(vector<int> &x, vector<int> &y){
	vector<int> v;
	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 4; j++) {
			int dx = x[i] - x[j], dy = y[i] - y[j];
			v.push_back(dx * dx + dy * dy);
		}
	sort(v.begin(), v.end());
	int l = v[0];
	if (l == 0) return false;
	return v[0]==l && v[1]==l && v[2]==l && v[3]==l && v[4]==l*2 && v[5]==l*2;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    vector<string> s(9);
    for(int i = 0; i < 9; i++) cin >> s[i];

    // 各点の座標を持つ
    vector<pair<int,int>> p;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(s[i][j] == '#'){
                p.push_back(pair<int,int>(i,j));
            }
        }
    }

    int ans = 0;
    // 4点を全探索
    for(int a = 0; a < (int)p.size(); a++){
        for(int b = a+1; b < (int)p.size(); b++){
            for(int c = b+1; c < (int)p.size(); c++){
                for(int d = c+1; d < (int)p.size(); d++){
                    vector<int> x,y;
                    x.push_back(p[a].first), y.push_back(p[a].second);
                    x.push_back(p[b].first), y.push_back(p[b].second);
                    x.push_back(p[c].first), y.push_back(p[c].second);
                    x.push_back(p[d].first), y.push_back(p[d].second);
                    if(check(x,y)) ans++;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}