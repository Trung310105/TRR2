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
int a[maxn][maxn], in[maxn], out[maxn];
bool used[maxn], vis[maxn][maxn];
set<int> g[maxn];

void dfs(int u)
{
    used[u] = true;
    for(int v : g[u])
    {
        if(!used[v]) dfs(v);
    }
}

void sol_1()
{
    cin >> n;
    memset(in, 0, sizeof in);
    memset(out, 0, sizeof out);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 1)
            {
                g[i].insert(j);
                g[j].insert(i);

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

    if(ccs == 1)
    {   
        int s = 0, t = 0;
        for(int i = 1;  i <= n; i++)
        {
            if(in[i] == out[i]) continue;
            else if((in[i] + 1) == out[i]) s++;
            else if(in[i] == (out[i] + 1)) t++;
            else
            {
                cout << "0\n";
                return;
            }
        }

        if(s == 0 && t == 0) cout << "1\n";
        else if(s == 1 && t == 1) cout << "2\n";
        else cout << "0\n";
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

    vector<int> path;
    stack<int> st;
    st.push(start);
    while(!st.empty())
    {
        int u = st.top();
        bool ok = false;
        for(int v = 1; v <= n; v++)
        {
            if(!vis[u][v] && a[u][v] == 1)
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
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    int type; cin >> type;
    if(type == 1) sol_1();
    else sol_2();
    return 0;
}
//Đức Trung - B23DCCN853