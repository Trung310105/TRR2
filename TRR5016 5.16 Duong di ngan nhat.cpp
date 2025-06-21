#include <bits/stdc++.h>
#define int long long
#define fater() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FOD(i,a,b) for(int i = a; i >= b; i--)
#define F(i,a,b) for(int i = a; i < b; i++)
#define FD(i,a,b) for(int i = a; i > b; i--)
#define pb push_back
#define reset(name, val) memset(name, val, sizeof name)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
const int maxn = 105;
const int INF = 10000;
const int mod = 1e9 + 7;

using namespace std;

int n, a[maxn][maxn], e[maxn][maxn];

signed main()
{
    fater();
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if(a[i][j] != INF && i != j)
            {
                e[i][j] = j;
            }
            else e[i][j] = -1;
        }
    }

    for(int id = 1; id <= n; id++)
    {
        for(int u = 1; u <= n; u++)
        {
            for(int v = 1; v <= n; v++)
            {
                if(a[u][id] != INF && a[u][id] != 0 && a[id][v] != INF && a[id][v] != 0 && (a[u][v] > a[u][id] + a[id][v]))
                {
                    a[u][v] = a[u][id] + a[id][v];
                    e[u][v] = e[u][id];
                }
            }
        }
    }

    int total = 0, s, t;
    for(int u = 1; u <= n; u++)
    {
        for(int v = 1; v <= n; v++)
        {
            if(a[u][v] != INF && a[u][v] != 0)
            {
                if(total < a[u][v])
                {
                    total = a[u][v];
                    s = u;
                    t = v;
                }
            }
        }
    }

    if(e[s][t] == -1)
    {
        cout << "0\n";
    }
    else
    {
        cout << s << ' ' << t << ' ' << total << '\n';
        vector<int> path;
        path.push_back(s);
        while(s != t)
        {
            s = e[s][t];
            path.push_back(s);
        }
        for(auto x : path) cout << x << ' ';
    }
    return 0;
}
//Đức Trung - B23DCCN853