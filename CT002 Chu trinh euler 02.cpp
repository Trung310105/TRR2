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

int n, a[maxn][maxn], start;
bool vis[maxn][maxn], used[maxn];

void dfs(int u)
{
    used[u] = true;
    for(int v = 1; v <= n; v++)
    {
        if(!used[v] && a[u][v] == 1)
        {
            dfs(v);
        }
    }
}

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
        for(int u = 1; u <= n; u++)
        {
            int cnt = 0;
            for(int v = 1; v <= n; v++)
            {
                if(a[u][v] == 1) cnt++;
            }
            if(cnt & 1) odd++;
        }

        if(odd == 2) cout << "2\n";
        else if(odd == 0) cout << "1\n";
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
            if(!vis[u][v] && a[u][v])
            {
                vis[u][v] = vis[v][u] = true;
                st.push(v);
                ok = true;
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
    if(type == 1)
    {
        sol_1();
    }
    else sol_2();
    return 0;
}
//Đức Trung - B23DCCN853