#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, w;
    cin >> n >> w;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    set<int> st;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= w)
            st.insert(a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] + a[j] <= w)
            {
                st.insert(a[i] + a[j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (a[i] + a[j] + a[k] <= w)
                {
                    st.insert(a[i] + a[j] + a[k]);
                }
            }
        }
    }

    cout << st.size() << endl;

    return 0;
}