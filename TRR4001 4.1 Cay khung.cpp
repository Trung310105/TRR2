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

int n, start;
int a[maxn][maxn], par[maxn];
bool used[maxn];
vector<pair<int,int>> edges;

void dfs(int u, int p)
{
    used[u] = true;
    if(u != start)
    {
        if(p < u) edges.push_back({p,u});
        else if(u < p) edges.push_back({u,p});
    }
    if(edges.size() == (n - 1)) return;
    for(int v = 1; v <= n; v++)
    {
        if(!used[v] && a[u][v] == 1)
        {
            dfs(v,u);
        }
    }
}

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    used[u] = true;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        if(x != start)
        {
            if(par[x] < x) edges.push_back({par[x], x});
            else edges.push_back({x, par[x]});
        }
        if(edges.size() == (n - 1)) return;
        for(int y = 1; y <= n; y++)
        {
            if(!used[y] && a[x][y] == 1)
            {
                used[y] = true;
                par[y] = x;
                q.push(y);
            }
        }
    }
}

void sol_1()
{
    cin >> n >> start;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    dfs(start,0);
    if(edges.size() == (n - 1))
    {
        cout << edges.size() << '\n';
        for(auto x : edges)
        {
            cout << x.first << ' ' << x.second << '\n';
        }
    }
    else cout << "0\n";
}

void sol_2()
{
    cin >> n >> start;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    bfs(start);
    if(edges.size() == (n - 1))
    {
        cout << edges.size() << '\n';
        for(auto x : edges)
        {
            cout << x.first << ' ' << x.second << '\n';
        }
    }
    else cout << "0\n";
}

signed main()
{
    fater();
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    int type; cin >> type;
    if(type == 1) sol_1();
    else sol_2();
    return 0;
}
//Đức Trung - B23DCCN853