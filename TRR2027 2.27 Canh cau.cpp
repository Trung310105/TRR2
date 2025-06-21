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

int n, a[maxn][maxn];
int id[maxn], low[maxn], dfs_cnt = 0;
set<pair<int,int>> edges;

void dfs(int u, int p)
{
    id[u] = low[u] = ++dfs_cnt;
    for(int v = 1; v <= n; v++)
    {
        if(a[u][v] == 1 && v == p) continue;
        if(a[u][v] == 1 && id[v]) low[u] = min(low[u], id[v]);
        else if(a[u][v] == 1 && !id[v])
        {
            dfs(v,u);
            low[u] = min(low[u], low[v]);

            if(low[v] > id[u])
            {
                edges.insert({u,v});
            }
        }
    }
}

signed main()
{
    fater();
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; i++)
    {
        if(!id[i])
        {
            dfs(i,0);
        }
    }

    cout << edges.size() << '\n';
    for(auto edge : edges) cout << edge.first << ' ' << edge.second << '\n';
    return 0;
}
//Đức Trung - B23DCCN853    