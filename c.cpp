#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, q;
    string s;
    cin >> n >> s >> q;

    bool rev = false;
    for (int i = 0; i < q; i++)
    {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1)
        {
            if (rev)
            {
                if (a <= n)
                    a += n;
                else
                    a -= n;
                if (b <= n)
                    b += n;
                else
                    b -= n;
                swap(s[a - 1], s[b - 1]);
            }
            else
            {
                swap(s[a - 1], s[b - 1]);
            }
        }
        if (t == 2)
        {
            if (rev)
                rev = false;
            else
                rev = true;
        }
    }

    if (rev)
    {
        string first = s.substr(0, n), second = s.substr(n);
        s = second + first;
    }

    cout << s << endl;

    return 0;
}