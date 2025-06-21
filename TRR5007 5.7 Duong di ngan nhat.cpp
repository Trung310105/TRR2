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

int n, s, t;
int a[maxn][maxn], dist[maxn], par[maxn];

void Bellman_ford()
{
    for(int i = 1; i <= n; i++) dist[i] = INT_MAX;
    dist[s] = 0;
    bool ok;
    for(int id = 1; id <= (n - 1); id++)
    {
        ok = false;
        for(int u = 1; u <= n; u++)
        {
            for(int v = 1; v <= n; v++)
            {
                if(a[u][v] != INF && a[u][v] != 0 && (dist[v] > dist[u] + a[u][v]))
                {
                    dist[v] = dist[u] + a[u][v];
                    par[v] = u;
                    ok = true;
                }
            }
        }
        if(!ok) break;
    }

    ok = false;
    for(int u = 1; u <= n; u++)
    {
        for(int v = 1; v <= n; v++)
        {
            if(a[u][v] != INF && a[u][v] != 0 && dist[v] != INT_MAX && (dist[v] > dist[u] + a[u][v]))
            {
                ok = true;
                break;
            }
        }
        if(ok) break;
    }
    if(ok) cout << "-1\n";
    else
    {
        if(dist[t] == INT_MAX) cout << "0\n";
        else
        {
            vector<int> path;
            int tmp = t;
            while(tmp != s)
            {
                path.push_back(tmp);
                tmp = par[tmp];
            }
            path.push_back(tmp);
            reverse(path.begin(), path.end());
            cout << dist[t] << '\n';
            for(auto x : path) cout << x << ' ';
        }
    }
}

signed main()
{
    fater();
    freopen("BN.INP", "r", stdin);
    freopen("BN.OUT", "w", stdout);
    cin >> n >> s >> t;
    for(int i = 1; i <= n ; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    Bellman_ford();
    return 0;
}
//Đức Trung - B23DCCN853