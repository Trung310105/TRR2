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

int n, a[maxn][maxn], ccs;
set<int> g[maxn], adj[maxn];
int id[maxn], low[maxn], dfs_cnt = 0;
stack<int> st;
bool used[maxn];

void Dfs(int u)
{
    used[u] = true;
    for(auto v : adj[u])
    {
        if(!used[v]) Dfs(v);
    }
}

void dfs(int u)
{
    id[u] = low[u] = ++dfs_cnt;
    st.push(u);
    for(auto v : g[u])
    {
        if(id[v]) low[u] = min(low[u], id[v]);
        else
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }

    if(id[u] == low[u])
    {
        ccs++;
        int v;
        do
        {
            v = st.top();
            st.pop();
            id[v] = low[v] = LONG_LONG_MAX;
        }while(v != u);
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
            if(a[i][j] == 1)
            {
                g[i].insert(j);
                adj[i].insert(j);
                adj[j].insert(i);
            }
        }
    }
    ccs = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!id[i])
        {
            dfs(i);
        }
    }
    if(ccs == 1)
    {
        cout << "1\n";
        return 0;
    }
    ccs = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!used[i])
        {
            ccs++;
            Dfs(i);
        }
    }
    if(ccs == 1)
    {
        cout << "2\n";
        return 0;
    }
    cout << "0\n";
}
//Đức Trung - B23DCCN853