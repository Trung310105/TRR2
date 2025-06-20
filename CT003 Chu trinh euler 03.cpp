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

int n, start, a[maxn][maxn];
set<int> g[maxn], adj[maxn];
int in[maxn], out[maxn];
bool used[maxn], vis[maxn][maxn];

void dfs(int u)
{
    used[u] = true;
    for(auto v : adj[u])
    {
        if(!used[v]) dfs(v);
    }
}

int sol_1()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int k; cin >> k;
        for(int j = 0; j < k; j++)
        {
            int x; cin >> x;
            a[i][x] = 1;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i][j])
            {
                adj[i].insert(j); 
                adj[j].insert(i);
                in[j]++;
                out[i]++;
            }
        }
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

    if(ccs != 1) return 0;

    int s = 0, t = 0;
    for(int i = 1; i <= n; i++)
    {
        if(in[i] == out[i]) continue;
        else if((in[i] + 1) == out[i]) s++;
        else if(in[i] == (out[i] + 1)) t++;
        else return 0;
    }

    if(s == 0 && t == 0) return 1;
    else if(s == 1 && t == 1) return 2;
    return 0;
}

void sol_2()
{
    cin >> n >> start;
    for(int i = 1; i <= n; i++)
    {
        int k; cin >> k;
        for(int j = 0; j < k; j++)
        {
            int x; cin >> x;
            g[i].insert(x);
        }
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
                vis[u][v] = true;
                ok = true;
                st.push(v);
                break;
            }
        }

        if(!ok)
        {
            path.push_back(st.top());
            st.pop();
        }
    }

    reverse(path.begin(), path.end());
    for(auto x : path) cout << x << ' ';
}

signed main()
{
    fater();
    int type; cin >> type;
    if(type == 1) cout << sol_1();
    else sol_2();
    return 0;
}
//Đức Trung - B23DCCN853    