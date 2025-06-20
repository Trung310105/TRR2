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

int n, m, start;
vector<int> g[maxn];
bool used[maxn], vis[maxn][maxn];

void dfs(int u)
{
    used[u] = true;
    for(auto v : g[u])
    {
        if(!used[v]) dfs(v);
    }
}

void sol_1()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y; 
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int ccs = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!used[i])
        {
            ccs++;
            dfs(i);
        }
    }

    if(ccs == 1)
    {
        int odd = 0;
        for(int i = 1; i <= n; i++)
        {
            if(g[i].size() & 1) odd++;
        }
        if(odd) cout << "2\n";
        else cout << "1\n";
    }
    else
    {
        cout << "0\n";
    }
}

void sol_2()
{
    cin >> n >> m >> start;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> path;
    stack<int> st;
    st.push(start);
    while(!st.empty())
    {
        int u = st.top();
        bool ok = false;
        for(auto v : g[u])
        {
            if(!vis[u][v])
            {
                vis[u][v] = vis[v][u] = true;
                ok = true;
                st.push(v);
                break;
            }
        }

        if(!ok)
        {
            while(!st.empty())
            {
                path.push_back(st.top());
                st.pop();
            }
        }
    }

    reverse(path.begin(), path.end());
    for(auto x : path) cout << x << ' ';
}

signed main()
{
    fater();
    int type; cin >> type;
    if(type == 1)
    {
        sol_1();
    }
    else{
        sol_2();
    }
    return 0;
}
//Đức Trung - B23DCCN853