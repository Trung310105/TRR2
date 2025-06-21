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
int a[maxn][maxn], dist[maxn];
bool used[maxn];
int par[maxn];

void Dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,s});
    while(!pq.empty())
    {
        auto [w, u] = pq.top();
        pq.pop();
        if(used[u]) continue;
        used[u] = true;
        if(u == t) return;
        for(int v = 1; v <= n; v++)
        {
            if(!used[v] && a[u][v] != INF && a[u][v] != 0 && (dist[v] > (dist[u] + a[u][v])))
            {
                dist[v] = dist[u] + a[u][v];
                par[v] = u;
                pq.push({dist[v],v});
            }
        }
    }
}

signed main()
{
    fater();
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);
    cin >> n >> s >> t;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    Dijkstra();
    if(used[t])
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
    else cout << "0\n";
    return 0;
}
//Đức Trung - B23DCCN853