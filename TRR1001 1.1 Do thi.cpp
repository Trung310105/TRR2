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
const int mod = 1e9 + 7;

using namespace std;

int n, a[maxn][maxn];

void sol_1()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int u = 1; u <= n; u++)
    {
        int cnt = 0;
        for(int v = 1; v <= n; v++)
        {
            if(a[u][v] == 1) cnt++;
        }
        cout << cnt << ' ';
    }
}

void sol_2()
{
    set<pair<int,int>> edges;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 1 && (i < j))
            {
                edges.insert({i,j});
            }
        }
    }

    cout << n << ' ' << edges.size() << '\n';
    for(auto x : edges) cout << x.first << ' ' << x.second << '\n';
}

signed main()
{
    fater();
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int type; cin >> type;
    if(type == 1)
    {
        sol_1();
    }
    else sol_2();
    return 0;
}
//Đức Trung - B23DCCN853