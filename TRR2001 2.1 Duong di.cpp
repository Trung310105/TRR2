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

int n, u, v;
int a[maxn][maxn], par[maxn];
bool used[maxn];

void dfs(int x)
{
    used[x] = true;
    for(int y = 1; y <= n; y++)
    {
        if(!used[y] && a[x][y] == 1)
        {
            par[y] = x;
            dfs(y);
        }
    }
}

void sol_1()
{
    cin >> n >> u >> v;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    int cnt = 0;
    for(int k = 1; k <= n; k++)
    {
        if(a[u][k] == 1 && a[k][v] == 1) cnt++;
    }

    cout << cnt << '\n';
}

void sol_2()
{
    cin >> n >> u >> v;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    dfs(u);
    if(used[v])
    {
        vector<int> path;
        while(v != u)
        {
            path.push_back(v);
            v = par[v];
        }
        path.push_back(v);
        reverse(path.begin(), path.end());
        for(auto &x : path) cout << x << ' ';
    }
    else cout << "0\n";
}

signed main()
{
    fater();
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    int type; cin >> type;
    if(type == 1) sol_1();
    else sol_2();
    return 0;
}
//Đức Trung - B23DCCN853